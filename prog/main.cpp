#include <iostream>
#include <cinttypes>

typedef uint16_t PipGirl_state_t;

constexpr const int PIPGIRL_STATE_COUNT = 5;
constexpr const PipGirl_state_t PIPGIRL_SANITAZATION_MASK = ~(-1 >> PIPGIRL_STATE_COUNT << PIPGIRL_STATE_COUNT);

enum class PipGirl_states : u_int16_t
{
    Invisibility = 0b0000'0000'0000'0001,
    Silence = 0b0000'0000'0000'0010,
    IRAbsorbption = 0b0000'0000'0000'0100,
    RFAbsorbption = 0b0000'0000'0000'1000,
    PotatoEnergyMode = 0b0000'0000'0001'0000,
};

// Is used to cut trash bits
PipGirl_state_t SanitateState(PipGirl_state_t state)
{
    return state & PIPGIRL_SANITAZATION_MASK;
}

/**
 * @brief Inverts module's state
 *
 * @param state Suit state
 * 
 * @param to_get Module id to toggle
 *
 * @return bool
 */
void InvertState(PipGirl_state_t &state, int to_invert)
{
    state ^= (1 << to_invert);
    state = SanitateState(state);
}

/**
 * @brief Checks wether a module of the suit is active
 *
 * @param state Suit state
 * 
 * @param to_get Module to read
 *
 * @return bool
 */
bool IsActive(PipGirl_state_t state, PipGirl_states to_get){
    return (state & static_cast<PipGirl_state_t>(to_get)) != 0;
}

/**
 * @brief Checks wether a module of the suit by id is active
 *
 * @param state Suit state
 * 
 * @param id Module id to read
 *
 * @return bool
 */
bool IsActiveByID(PipGirl_state_t state, int id)
{
    return (SanitateState(state) >> id) & 1;
}

/**
 * @brief Counts suit's currently active states
 *
 * @param state Suit states
 *
 * @return unsigned int
 */
unsigned int CountActiveStates(PipGirl_state_t state)
{
           //basically counts 1s
    return __builtin_popcountll(SanitateState(state));
}

/**
 * @brief Checks wether marmelade donkeys can detect a guy in a suit with enabled active sates
 *
 * @param state Suit states
 *
 * @return bool
 */
bool IsDetected(PipGirl_state_t state)
{
    // When Potato mode active, then no modules can work
    if (IsActive(state,PipGirl_states::PotatoEnergyMode))
        return true;
    
    // The perimeter sweepers WILL see you without invisibility
    if (!IsActive(state,PipGirl_states::Invisibility)) 
        return true;
    
    // Marmelade donkeys have a watchtower with a sniper
    // that has a thermal imaging scope
    if (!IsActive(state,PipGirl_states::IRAbsorbption))
        return true;

    
    /*
     * Because marmelade donkeys dont have ears, you
     * dont need silence mode
     * and also bruh you're not a jet to have radar
     * absorbption
     */ 
    return false;
}

int main(int argc, char const *argv[])
{
    PipGirl_state_t suit = 0; // All modules disabled
    InvertState(suit,0); // Invis enabled
    InvertState(suit,2); // Infrared absorbption enabled
    bool active = IsActiveByID(suit,2); // Returns true, because IR absorbption is enabled
    int state_cnt = CountActiveStates(suit); // Returns 2
    bool detected = IsDetected(suit); // Returns false
    InvertState(suit,4); // Enables energy saving mode
    detected = IsDetected(suit); // Returns true

    return 0;
}