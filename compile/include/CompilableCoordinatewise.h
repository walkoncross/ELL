////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Rockmill
//  File:     CompilableCoordinatewise.h (compile)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CompilableLayer.h"

// layers
#include "Coordinatewise.h"

// stl
#include <cstdint>

/// <summary> A struct that adds printing capabilities to a layer. </summary>
class CompilableCoordinatewise : public layers::Coordinatewise, public CompilableLayer
{
public:
    /// <summary> Returns the number of elements in the layer. </summary>
    ///
    /// <returns> The number of elements in the layer. </returns>
    virtual uint64_t Size() const override;

    /// <summary> Assignment operator from Coordinatewise. </summary>
    ///
    /// <param name="coordinatewise"> The coordinatewise layer to assign from.</param>
    void operator=(const layers::Coordinatewise& coordinatewise);

    /// <summary> Assignment operator from Layer. </summary>
    ///
    /// <param name="layer"> The layer being copied. </param>
    virtual void operator=(const layers::Layer& layer) override;

    /// <summary> Pushes actions upward in the graph </summary>
    ///
    /// <param name="currentLayerIndex"> The index of the current layer. </param>
    /// <param name="graph"> [in,out] The data flow graph. </param>
    virtual void SetActions(uint64_t currentLayerIndex, DataFlowGraph& graph) const override;
};