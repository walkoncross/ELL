////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     OutputPort.tcc (model)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

/// <summary> model namespace </summary>
namespace model
{
    //
    // OutputPort
    //
    template <typename ValueType>
    OutputPort<ValueType>::OutputPort(const class Node* node, size_t size) : OutputPortBase(node, OutputPortBase::GetTypeCode<ValueType>(), size)
    {}

    template <typename ValueType>
    ValueType OutputPort<ValueType>::GetOutput(size_t index) const
    { 
        return _cachedOutput[index]; 
    }

    template <typename ValueType>
    void OutputPort<ValueType>::SetOutput(std::vector<ValueType> values) const
    {
        _cachedOutput = values;
    }

	template <typename ValueType>
	void OutputPort<ValueType>::SetOutput(ValueType value) const
	{
		_cachedOutput.clear();
		_cachedOutput.push_back(value);
	}
}
