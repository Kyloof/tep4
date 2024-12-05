cmake_minimum_required(VERSION 3.29)
project(tep4)
include_directories(
        src/NodeInterface
        src/NodeTypes/Literal
        src/NodeTypes/Operator
        src/NodeTypes/Variable

)
set(CMAKE_CXX_STANDARD 20)

add_executable(tep4
        src/CError/CError.h
        src/CError/CError.cpp
        src/CResult/CResult.cpp
        src/CResult/CResult.h
        src/AbstractSyntaxTree/AbstractSyntaxTree.cpp
        src/AbstractSyntaxTree/AbstractSyntaxTree.h
        src/NodeInterface/INode.h
        src/NodeTypes/Literal/Literal.cpp
        src/NodeTypes/Literal/Literal.h
        src/OperatorType/BinaryOperator/ABinaryOperator.cpp
        src/OperatorType/BinaryOperator/ABinaryOperator.h
        src/NodeTypes/Variable/Variable.cpp
        src/NodeTypes/Variable/Variable.h
        src/OperatorsFunc/BinaryOperatorsFunc/Addition/Addition.cpp
        src/OperatorsFunc/BinaryOperatorsFunc/Addition/Addition.h
        src/OperatorsFunc/BinaryOperatorsFunc/Divide/Divide.cpp
        src/OperatorsFunc/BinaryOperatorsFunc/Divide/Divide.h
        src/OperatorsFunc/BinaryOperatorsFunc/Multiply/Multiply.cpp
        src/OperatorsFunc/BinaryOperatorsFunc/Multiply/Multiply.h
        src/OperatorsFunc/BinaryOperatorsFunc/Substract/Subtract.cpp
        src/OperatorsFunc/BinaryOperatorsFunc/Substract/Subtract.h
        src/Command/Command.cpp
        src/Command/Command.h
        src/OperatorType/UniOperator/AUniOperator.cpp
        src/OperatorType/UniOperator/AUniOperator.h
        src/NodeTypes/Operator/AOperator.h
        src/NodeTypes/Operator/AOperator.cpp
        src/OperatorsFunc/UniOperatorsFunc/Sinus/Sinus.cpp
        src/OperatorsFunc/UniOperatorsFunc/Sinus/Sinus.h
        src/OperatorsFunc/UniOperatorsFunc/Cos/Cos.cpp
        src/OperatorsFunc/UniOperatorsFunc/Cos/Cos.h
        main.cpp
        src/Save/Save.h
)
