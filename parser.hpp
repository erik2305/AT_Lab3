// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file parser.hpp
 ** Define the ParserNS::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 23 "parser.y"

    #include "ast.h"
    #include <vector>
    #include <string>

#line 55 "parser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 17 "parser.y"
namespace ParserNS {
#line 191 "parser.hpp"




  /// A Bison parser.
  class ParserClass
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // program
      // statement
      // assignment
      // function_call
      // variable_declaration
      // constant_declaration
      // array_declaration
      // array_extension
      // increment
      // decrement
      // loop
      // conditional
      // function_declaration
      // robot_operation
      // group_of_statements
      // expression
      // array_access
      // movement_operator
      // sensor_operator
      char dummy1[sizeof (ASTNode*)];

      // BOOL_CONST
      char dummy2[sizeof (bool)];

      // UNSIGNED_INT
      char dummy3[sizeof (int)];

      // IDENTIFIER
      char dummy4[sizeof (std::string)];

      // statements
      // expressions
      // return_variables
      // parameters
      // variables
      char dummy5[sizeof (std::vector<ASTNode*>*)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    UNSIGNED_INT = 258,            // UNSIGNED_INT
    BOOL_CONST = 259,              // BOOL_CONST
    IDENTIFIER = 260,              // IDENTIFIER
    ASSIGN = 261,                  // ASSIGN
    SEMICOLON = 262,               // SEMICOLON
    COMMA = 263,                   // COMMA
    LPAREN = 264,                  // LPAREN
    RPAREN = 265,                  // RPAREN
    LBRACKET = 266,                // LBRACKET
    RBRACKET = 267,                // RBRACKET
    LBRACE = 268,                  // LBRACE
    RBRACE = 269,                  // RBRACE
    PLUS = 270,                    // PLUS
    MINUS = 271,                   // MINUS
    MULTIPLY = 272,                // MULTIPLY
    DIVIDE = 273,                  // DIVIDE
    MODULO = 274,                  // MODULO
    INC = 275,                     // INC
    DEC = 276,                     // DEC
    NOT = 277,                     // NOT
    OR = 278,                      // OR
    GT = 279,                      // GT
    LT = 280,                      // LT
    UINT = 281,                    // UINT
    BOOLEAN = 282,                 // BOOLEAN
    CUINT = 283,                   // CUINT
    CBOOLEAN = 284,                // CBOOLEAN
    ARRAY1DBOOL = 285,             // ARRAY1DBOOL
    ARRAY2DBOOL = 286,             // ARRAY2DBOOL
    ARRAY1DUINT = 287,             // ARRAY1DUINT
    ARRAY2DUINT = 288,             // ARRAY2DUINT
    EXTEND1 = 289,                 // EXTEND1
    EXTEND2 = 290,                 // EXTEND2
    SIZE1 = 291,                   // SIZE1
    SIZE2 = 292,                   // SIZE2
    WHILE = 293,                   // WHILE
    DO = 294,                      // DO
    IF = 295,                      // IF
    ELSE = 296,                    // ELSE
    FUNCTION = 297,                // FUNCTION
    FORW = 298,                    // FORW
    BACK = 299,                    // BACK
    RIGHT_OP = 300,                // RIGHT_OP
    LEFT_OP = 301,                 // LEFT_OP
    GETF = 302,                    // GETF
    GETB = 303,                    // GETB
    GETR = 304,                    // GETR
    GETL = 305,                    // GETL
    PUSHF = 306,                   // PUSHF
    PUSHB = 307,                   // PUSHB
    PUSHR = 308,                   // PUSHR
    PUSHL = 309,                   // PUSHL
    UNDO = 310                     // UNDO
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 56, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_UNSIGNED_INT = 3,                      // UNSIGNED_INT
        S_BOOL_CONST = 4,                        // BOOL_CONST
        S_IDENTIFIER = 5,                        // IDENTIFIER
        S_ASSIGN = 6,                            // ASSIGN
        S_SEMICOLON = 7,                         // SEMICOLON
        S_COMMA = 8,                             // COMMA
        S_LPAREN = 9,                            // LPAREN
        S_RPAREN = 10,                           // RPAREN
        S_LBRACKET = 11,                         // LBRACKET
        S_RBRACKET = 12,                         // RBRACKET
        S_LBRACE = 13,                           // LBRACE
        S_RBRACE = 14,                           // RBRACE
        S_PLUS = 15,                             // PLUS
        S_MINUS = 16,                            // MINUS
        S_MULTIPLY = 17,                         // MULTIPLY
        S_DIVIDE = 18,                           // DIVIDE
        S_MODULO = 19,                           // MODULO
        S_INC = 20,                              // INC
        S_DEC = 21,                              // DEC
        S_NOT = 22,                              // NOT
        S_OR = 23,                               // OR
        S_GT = 24,                               // GT
        S_LT = 25,                               // LT
        S_UINT = 26,                             // UINT
        S_BOOLEAN = 27,                          // BOOLEAN
        S_CUINT = 28,                            // CUINT
        S_CBOOLEAN = 29,                         // CBOOLEAN
        S_ARRAY1DBOOL = 30,                      // ARRAY1DBOOL
        S_ARRAY2DBOOL = 31,                      // ARRAY2DBOOL
        S_ARRAY1DUINT = 32,                      // ARRAY1DUINT
        S_ARRAY2DUINT = 33,                      // ARRAY2DUINT
        S_EXTEND1 = 34,                          // EXTEND1
        S_EXTEND2 = 35,                          // EXTEND2
        S_SIZE1 = 36,                            // SIZE1
        S_SIZE2 = 37,                            // SIZE2
        S_WHILE = 38,                            // WHILE
        S_DO = 39,                               // DO
        S_IF = 40,                               // IF
        S_ELSE = 41,                             // ELSE
        S_FUNCTION = 42,                         // FUNCTION
        S_FORW = 43,                             // FORW
        S_BACK = 44,                             // BACK
        S_RIGHT_OP = 45,                         // RIGHT_OP
        S_LEFT_OP = 46,                          // LEFT_OP
        S_GETF = 47,                             // GETF
        S_GETB = 48,                             // GETB
        S_GETR = 49,                             // GETR
        S_GETL = 50,                             // GETL
        S_PUSHF = 51,                            // PUSHF
        S_PUSHB = 52,                            // PUSHB
        S_PUSHR = 53,                            // PUSHR
        S_PUSHL = 54,                            // PUSHL
        S_UNDO = 55,                             // UNDO
        S_YYACCEPT = 56,                         // $accept
        S_program = 57,                          // program
        S_statement = 58,                        // statement
        S_assignment = 59,                       // assignment
        S_function_call = 60,                    // function_call
        S_variable_declaration = 61,             // variable_declaration
        S_constant_declaration = 62,             // constant_declaration
        S_array_declaration = 63,                // array_declaration
        S_array_extension = 64,                  // array_extension
        S_increment = 65,                        // increment
        S_decrement = 66,                        // decrement
        S_loop = 67,                             // loop
        S_conditional = 68,                      // conditional
        S_function_declaration = 69,             // function_declaration
        S_robot_operation = 70,                  // robot_operation
        S_group_of_statements = 71,              // group_of_statements
        S_statements = 72,                       // statements
        S_expression = 73,                       // expression
        S_array_access = 74,                     // array_access
        S_expressions = 75,                      // expressions
        S_return_variables = 76,                 // return_variables
        S_parameters = 77,                       // parameters
        S_variables = 78,                        // variables
        S_movement_operator = 79,                // movement_operator
        S_sensor_operator = 80                   // sensor_operator
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_constant_declaration: // constant_declaration
      case symbol_kind::S_array_declaration: // array_declaration
      case symbol_kind::S_array_extension: // array_extension
      case symbol_kind::S_increment: // increment
      case symbol_kind::S_decrement: // decrement
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_robot_operation: // robot_operation
      case symbol_kind::S_group_of_statements: // group_of_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_array_access: // array_access
      case symbol_kind::S_movement_operator: // movement_operator
      case symbol_kind::S_sensor_operator: // sensor_operator
        value.move< ASTNode* > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.move< std::vector<ASTNode*>* > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ASTNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ASTNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<ASTNode*>*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<ASTNode*>*& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_constant_declaration: // constant_declaration
      case symbol_kind::S_array_declaration: // array_declaration
      case symbol_kind::S_array_extension: // array_extension
      case symbol_kind::S_increment: // increment
      case symbol_kind::S_decrement: // decrement
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_robot_operation: // robot_operation
      case symbol_kind::S_group_of_statements: // group_of_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_array_access: // array_access
      case symbol_kind::S_movement_operator: // movement_operator
      case symbol_kind::S_sensor_operator: // sensor_operator
        value.template destroy< ASTNode* > ();
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.template destroy< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.template destroy< std::vector<ASTNode*>* > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return ParserClass::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const bool& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    ParserClass ();
    virtual ~ParserClass ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    ParserClass (const ParserClass&) = delete;
    /// Non copyable.
    ParserClass& operator= (const ParserClass&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED_INT (int v)
      {
        return symbol_type (token::UNSIGNED_INT, std::move (v));
      }
#else
      static
      symbol_type
      make_UNSIGNED_INT (const int& v)
      {
        return symbol_type (token::UNSIGNED_INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL_CONST (bool v)
      {
        return symbol_type (token::BOOL_CONST, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOL_CONST (const bool& v)
      {
        return symbol_type (token::BOOL_CONST, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v)
      {
        return symbol_type (token::IDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v)
      {
        return symbol_type (token::IDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN ()
      {
        return symbol_type (token::ASSIGN);
      }
#else
      static
      symbol_type
      make_ASSIGN ()
      {
        return symbol_type (token::ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON ()
      {
        return symbol_type (token::SEMICOLON);
      }
#else
      static
      symbol_type
      make_SEMICOLON ()
      {
        return symbol_type (token::SEMICOLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#else
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN ()
      {
        return symbol_type (token::LPAREN);
      }
#else
      static
      symbol_type
      make_LPAREN ()
      {
        return symbol_type (token::LPAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN ()
      {
        return symbol_type (token::RPAREN);
      }
#else
      static
      symbol_type
      make_RPAREN ()
      {
        return symbol_type (token::RPAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET ()
      {
        return symbol_type (token::LBRACKET);
      }
#else
      static
      symbol_type
      make_LBRACKET ()
      {
        return symbol_type (token::LBRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET ()
      {
        return symbol_type (token::RBRACKET);
      }
#else
      static
      symbol_type
      make_RBRACKET ()
      {
        return symbol_type (token::RBRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE ()
      {
        return symbol_type (token::LBRACE);
      }
#else
      static
      symbol_type
      make_LBRACE ()
      {
        return symbol_type (token::LBRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE ()
      {
        return symbol_type (token::RBRACE);
      }
#else
      static
      symbol_type
      make_RBRACE ()
      {
        return symbol_type (token::RBRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::PLUS);
      }
#else
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::PLUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::MINUS);
      }
#else
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::MINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTIPLY ()
      {
        return symbol_type (token::MULTIPLY);
      }
#else
      static
      symbol_type
      make_MULTIPLY ()
      {
        return symbol_type (token::MULTIPLY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE ()
      {
        return symbol_type (token::DIVIDE);
      }
#else
      static
      symbol_type
      make_DIVIDE ()
      {
        return symbol_type (token::DIVIDE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULO ()
      {
        return symbol_type (token::MODULO);
      }
#else
      static
      symbol_type
      make_MODULO ()
      {
        return symbol_type (token::MODULO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC ()
      {
        return symbol_type (token::INC);
      }
#else
      static
      symbol_type
      make_INC ()
      {
        return symbol_type (token::INC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC ()
      {
        return symbol_type (token::DEC);
      }
#else
      static
      symbol_type
      make_DEC ()
      {
        return symbol_type (token::DEC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#else
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#else
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT ()
      {
        return symbol_type (token::GT);
      }
#else
      static
      symbol_type
      make_GT ()
      {
        return symbol_type (token::GT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT ()
      {
        return symbol_type (token::LT);
      }
#else
      static
      symbol_type
      make_LT ()
      {
        return symbol_type (token::LT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT ()
      {
        return symbol_type (token::UINT);
      }
#else
      static
      symbol_type
      make_UINT ()
      {
        return symbol_type (token::UINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN ()
      {
        return symbol_type (token::BOOLEAN);
      }
#else
      static
      symbol_type
      make_BOOLEAN ()
      {
        return symbol_type (token::BOOLEAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CUINT ()
      {
        return symbol_type (token::CUINT);
      }
#else
      static
      symbol_type
      make_CUINT ()
      {
        return symbol_type (token::CUINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CBOOLEAN ()
      {
        return symbol_type (token::CBOOLEAN);
      }
#else
      static
      symbol_type
      make_CBOOLEAN ()
      {
        return symbol_type (token::CBOOLEAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY1DBOOL ()
      {
        return symbol_type (token::ARRAY1DBOOL);
      }
#else
      static
      symbol_type
      make_ARRAY1DBOOL ()
      {
        return symbol_type (token::ARRAY1DBOOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY2DBOOL ()
      {
        return symbol_type (token::ARRAY2DBOOL);
      }
#else
      static
      symbol_type
      make_ARRAY2DBOOL ()
      {
        return symbol_type (token::ARRAY2DBOOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY1DUINT ()
      {
        return symbol_type (token::ARRAY1DUINT);
      }
#else
      static
      symbol_type
      make_ARRAY1DUINT ()
      {
        return symbol_type (token::ARRAY1DUINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY2DUINT ()
      {
        return symbol_type (token::ARRAY2DUINT);
      }
#else
      static
      symbol_type
      make_ARRAY2DUINT ()
      {
        return symbol_type (token::ARRAY2DUINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTEND1 ()
      {
        return symbol_type (token::EXTEND1);
      }
#else
      static
      symbol_type
      make_EXTEND1 ()
      {
        return symbol_type (token::EXTEND1);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTEND2 ()
      {
        return symbol_type (token::EXTEND2);
      }
#else
      static
      symbol_type
      make_EXTEND2 ()
      {
        return symbol_type (token::EXTEND2);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE1 ()
      {
        return symbol_type (token::SIZE1);
      }
#else
      static
      symbol_type
      make_SIZE1 ()
      {
        return symbol_type (token::SIZE1);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE2 ()
      {
        return symbol_type (token::SIZE2);
      }
#else
      static
      symbol_type
      make_SIZE2 ()
      {
        return symbol_type (token::SIZE2);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#else
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::DO);
      }
#else
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::DO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#else
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#else
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#else
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORW ()
      {
        return symbol_type (token::FORW);
      }
#else
      static
      symbol_type
      make_FORW ()
      {
        return symbol_type (token::FORW);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BACK ()
      {
        return symbol_type (token::BACK);
      }
#else
      static
      symbol_type
      make_BACK ()
      {
        return symbol_type (token::BACK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_OP ()
      {
        return symbol_type (token::RIGHT_OP);
      }
#else
      static
      symbol_type
      make_RIGHT_OP ()
      {
        return symbol_type (token::RIGHT_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_OP ()
      {
        return symbol_type (token::LEFT_OP);
      }
#else
      static
      symbol_type
      make_LEFT_OP ()
      {
        return symbol_type (token::LEFT_OP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GETF ()
      {
        return symbol_type (token::GETF);
      }
#else
      static
      symbol_type
      make_GETF ()
      {
        return symbol_type (token::GETF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GETB ()
      {
        return symbol_type (token::GETB);
      }
#else
      static
      symbol_type
      make_GETB ()
      {
        return symbol_type (token::GETB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GETR ()
      {
        return symbol_type (token::GETR);
      }
#else
      static
      symbol_type
      make_GETR ()
      {
        return symbol_type (token::GETR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GETL ()
      {
        return symbol_type (token::GETL);
      }
#else
      static
      symbol_type
      make_GETL ()
      {
        return symbol_type (token::GETL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUSHF ()
      {
        return symbol_type (token::PUSHF);
      }
#else
      static
      symbol_type
      make_PUSHF ()
      {
        return symbol_type (token::PUSHF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUSHB ()
      {
        return symbol_type (token::PUSHB);
      }
#else
      static
      symbol_type
      make_PUSHB ()
      {
        return symbol_type (token::PUSHB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUSHR ()
      {
        return symbol_type (token::PUSHR);
      }
#else
      static
      symbol_type
      make_PUSHR ()
      {
        return symbol_type (token::PUSHR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUSHL ()
      {
        return symbol_type (token::PUSHL);
      }
#else
      static
      symbol_type
      make_PUSHL ()
      {
        return symbol_type (token::PUSHL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDO ()
      {
        return symbol_type (token::UNDO);
      }
#else
      static
      symbol_type
      make_UNDO ()
      {
        return symbol_type (token::UNDO);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    ParserClass (const ParserClass&);
    /// Non copyable.
    ParserClass& operator= (const ParserClass&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 337,     ///< Last index in yytable_.
      yynnts_ = 25,  ///< Number of nonterminal symbols.
      yyfinal_ = 2 ///< Termination state number.
    };



  };

  inline
  ParserClass::symbol_kind_type
  ParserClass::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    // Last valid token kind.
    const int code_max = 310;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  ParserClass::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_constant_declaration: // constant_declaration
      case symbol_kind::S_array_declaration: // array_declaration
      case symbol_kind::S_array_extension: // array_extension
      case symbol_kind::S_increment: // increment
      case symbol_kind::S_decrement: // decrement
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_robot_operation: // robot_operation
      case symbol_kind::S_group_of_statements: // group_of_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_array_access: // array_access
      case symbol_kind::S_movement_operator: // movement_operator
      case symbol_kind::S_sensor_operator: // sensor_operator
        value.copy< ASTNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.copy< std::vector<ASTNode*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  ParserClass::symbol_kind_type
  ParserClass::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  ParserClass::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  ParserClass::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_constant_declaration: // constant_declaration
      case symbol_kind::S_array_declaration: // array_declaration
      case symbol_kind::S_array_extension: // array_extension
      case symbol_kind::S_increment: // increment
      case symbol_kind::S_decrement: // decrement
      case symbol_kind::S_loop: // loop
      case symbol_kind::S_conditional: // conditional
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_robot_operation: // robot_operation
      case symbol_kind::S_group_of_statements: // group_of_statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_array_access: // array_access
      case symbol_kind::S_movement_operator: // movement_operator
      case symbol_kind::S_sensor_operator: // sensor_operator
        value.move< ASTNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.move< std::vector<ASTNode*>* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  ParserClass::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  ParserClass::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  ParserClass::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  ParserClass::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  ParserClass::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  ParserClass::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  ParserClass::symbol_kind_type
  ParserClass::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  ParserClass::symbol_kind_type
  ParserClass::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 17 "parser.y"
} // ParserNS
#line 2407 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
