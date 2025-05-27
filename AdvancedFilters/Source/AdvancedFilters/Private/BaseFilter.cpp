#include "BaseFilter.h"

void UBaseFilterObject::Reset()
{
    CurrentEstimate = 0.0f;
    CurrentEstimateVector = FVector::ZeroVector;
    bIsInitialized = false;
}