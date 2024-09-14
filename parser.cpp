// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "parser.y"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ast.h"
#include "symbol_table.h"

// Forward declarations
int yylex(ParserNS::ParserClass::semantic_type *yylval);
void yyerror(const std::string& message);

extern ASTNode *ast_root;

#line 55 "parser.cpp"


#include "parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 17 "parser.y"
namespace ParserNS {
#line 134 "parser.cpp"

  /// Build a parser object.
  ParserClass::ParserClass ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  ParserClass::~ParserClass ()
  {}

  ParserClass::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  ParserClass::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  ParserClass::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  ParserClass::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  ParserClass::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  ParserClass::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  ParserClass::symbol_kind_type
  ParserClass::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  ParserClass::stack_symbol_type::stack_symbol_type ()
  {}

  ParserClass::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
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
        value.YY_MOVE_OR_COPY< ASTNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.YY_MOVE_OR_COPY< std::vector<ASTNode*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  ParserClass::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
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
        value.move< ASTNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.move< std::vector<ASTNode*>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  ParserClass::stack_symbol_type&
  ParserClass::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
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
        value.copy< ASTNode* > (that.value);
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.copy< std::vector<ASTNode*>* > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  ParserClass::stack_symbol_type&
  ParserClass::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
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
        value.move< ASTNode* > (that.value);
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        value.move< std::vector<ASTNode*>* > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  ParserClass::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  ParserClass::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  ParserClass::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  ParserClass::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  ParserClass::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  ParserClass::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ParserClass::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ParserClass::debug_level_type
  ParserClass::debug_level () const
  {
    return yydebug_;
  }

  void
  ParserClass::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  ParserClass::state_type
  ParserClass::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  ParserClass::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  ParserClass::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ParserClass::operator() ()
  {
    return parse ();
  }

  int
  ParserClass::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
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
        yylhs.value.emplace< ASTNode* > ();
        break;

      case symbol_kind::S_BOOL_CONST: // BOOL_CONST
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_UNSIGNED_INT: // UNSIGNED_INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_return_variables: // return_variables
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_variables: // variables
        yylhs.value.emplace< std::vector<ASTNode*>* > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: %empty
#line 63 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new BlockNode(new std::vector<ASTNode*>());
            ast_root = yylhs.value.as < ASTNode* > ();
        }
#line 728 "parser.cpp"
    break;

  case 3: // program: program statement
#line 68 "parser.y"
        {
            static_cast<BlockNode*>(yystack_[1].value.as < ASTNode* > ())->addStatement(yystack_[0].value.as < ASTNode* > ());
            yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > ();
        }
#line 737 "parser.cpp"
    break;

  case 4: // statement: variable_declaration
#line 75 "parser.y"
    { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 743 "parser.cpp"
    break;

  case 5: // statement: constant_declaration
#line 76 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 749 "parser.cpp"
    break;

  case 6: // statement: array_declaration
#line 77 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 755 "parser.cpp"
    break;

  case 7: // statement: array_extension
#line 78 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 761 "parser.cpp"
    break;

  case 8: // statement: assignment
#line 79 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 767 "parser.cpp"
    break;

  case 9: // statement: function_call
#line 80 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 773 "parser.cpp"
    break;

  case 10: // statement: increment
#line 81 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 779 "parser.cpp"
    break;

  case 11: // statement: decrement
#line 82 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 785 "parser.cpp"
    break;

  case 12: // statement: loop
#line 83 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 791 "parser.cpp"
    break;

  case 13: // statement: conditional
#line 84 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 797 "parser.cpp"
    break;

  case 14: // statement: function_declaration
#line 85 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 803 "parser.cpp"
    break;

  case 15: // statement: robot_operation
#line 86 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 809 "parser.cpp"
    break;

  case 16: // statement: group_of_statements
#line 87 "parser.y"
      { yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > (); }
#line 815 "parser.cpp"
    break;

  case 17: // assignment: IDENTIFIER ASSIGN expression SEMICOLON
#line 92 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new AssignmentNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < ASTNode* > ());
        }
#line 823 "parser.cpp"
    break;

  case 18: // assignment: array_access ASSIGN expression SEMICOLON
#line 96 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayAssignmentNode(yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ());
        }
#line 831 "parser.cpp"
    break;

  case 19: // function_call: IDENTIFIER LPAREN expressions RPAREN SEMICOLON
#line 103 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new FunctionCallNode(yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::vector<ASTNode*>* > ());
        }
#line 839 "parser.cpp"
    break;

  case 20: // variable_declaration: UINT IDENTIFIER ASSIGN expression SEMICOLON
#line 110 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new VarDeclarationNode(yystack_[3].value.as < std::string > (), VarType::UINT, yystack_[1].value.as < ASTNode* > ());
        }
#line 847 "parser.cpp"
    break;

  case 21: // variable_declaration: BOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
#line 114 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new VarDeclarationNode(yystack_[3].value.as < std::string > (), VarType::BOOLEAN, yystack_[1].value.as < ASTNode* > ());
        }
#line 855 "parser.cpp"
    break;

  case 22: // constant_declaration: CUINT IDENTIFIER ASSIGN expression SEMICOLON
#line 121 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ConstDeclarationNode(yystack_[3].value.as < std::string > (), VarType::UINT, yystack_[1].value.as < ASTNode* > ());
        }
#line 863 "parser.cpp"
    break;

  case 23: // constant_declaration: CBOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
#line 125 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ConstDeclarationNode(yystack_[3].value.as < std::string > (), VarType::BOOLEAN, yystack_[1].value.as < ASTNode* > ());
        }
#line 871 "parser.cpp"
    break;

  case 24: // array_declaration: ARRAY1DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 132 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayDeclarationNode(yystack_[5].value.as < std::string > (), VarType::BOOLEAN, 1, yystack_[2].value.as < std::vector<ASTNode*>* > ());
        }
#line 879 "parser.cpp"
    break;

  case 25: // array_declaration: ARRAY2DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 136 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayDeclarationNode(yystack_[5].value.as < std::string > (), VarType::BOOLEAN, 2, yystack_[2].value.as < std::vector<ASTNode*>* > ());
        }
#line 887 "parser.cpp"
    break;

  case 26: // array_declaration: ARRAY1DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 140 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayDeclarationNode(yystack_[5].value.as < std::string > (), VarType::UINT, 1, yystack_[2].value.as < std::vector<ASTNode*>* > ());
        }
#line 895 "parser.cpp"
    break;

  case 27: // array_declaration: ARRAY2DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 144 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayDeclarationNode(yystack_[5].value.as < std::string > (), VarType::UINT, 2, yystack_[2].value.as < std::vector<ASTNode*>* > ());
        }
#line 903 "parser.cpp"
    break;

  case 28: // array_extension: EXTEND1 IDENTIFIER expression SEMICOLON
#line 151 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayExtensionNode(yystack_[2].value.as < std::string > (), 1, yystack_[1].value.as < ASTNode* > (), nullptr);
        }
#line 911 "parser.cpp"
    break;

  case 29: // array_extension: EXTEND2 IDENTIFIER expression COMMA expression SEMICOLON
#line 155 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayExtensionNode(yystack_[4].value.as < std::string > (), 2, yystack_[3].value.as < ASTNode* > (), yystack_[1].value.as < ASTNode* > ());
        }
#line 919 "parser.cpp"
    break;

  case 30: // increment: INC IDENTIFIER SEMICOLON
#line 162 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new IncDecNode(yystack_[1].value.as < std::string > (), 1);
        }
#line 927 "parser.cpp"
    break;

  case 31: // decrement: DEC IDENTIFIER SEMICOLON
#line 169 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new IncDecNode(yystack_[1].value.as < std::string > (), -1);
        }
#line 935 "parser.cpp"
    break;

  case 32: // loop: WHILE LPAREN expression RPAREN DO group_of_statements
#line 176 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new WhileNode(yystack_[3].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 943 "parser.cpp"
    break;

  case 33: // conditional: IF LPAREN expression RPAREN group_of_statements
#line 183 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new IfNode(yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 951 "parser.cpp"
    break;

  case 34: // conditional: IF LPAREN expression RPAREN group_of_statements ELSE group_of_statements
#line 187 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new IfNode(yystack_[4].value.as < ASTNode* > (), yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 959 "parser.cpp"
    break;

  case 35: // function_declaration: return_variables FUNCTION IDENTIFIER LPAREN parameters RPAREN group_of_statements
#line 194 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new FunctionDeclarationNode(yystack_[4].value.as < std::string > (), yystack_[6].value.as < std::vector<ASTNode*>* > (), yystack_[2].value.as < std::vector<ASTNode*>* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 967 "parser.cpp"
    break;

  case 36: // robot_operation: movement_operator SEMICOLON
#line 201 "parser.y"
        { yylhs.value.as < ASTNode* > () = new RobotOperationNode(yystack_[1].value.as < ASTNode* > ()); }
#line 973 "parser.cpp"
    break;

  case 37: // robot_operation: sensor_operator SEMICOLON
#line 203 "parser.y"
        { yylhs.value.as < ASTNode* > () = new RobotOperationNode(yystack_[1].value.as < ASTNode* > ()); }
#line 979 "parser.cpp"
    break;

  case 38: // group_of_statements: LBRACE statements RBRACE
#line 208 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new BlockNode(yystack_[1].value.as < std::vector<ASTNode*>* > ());
            delete yystack_[1].value.as < std::vector<ASTNode*>* > (); // Clean up the vector as it's now encapsulated within BlockNode
        }
#line 988 "parser.cpp"
    break;

  case 39: // statements: %empty
#line 216 "parser.y"
        {
            yylhs.value.as < std::vector<ASTNode*>* > () = new std::vector<ASTNode*>();
        }
#line 996 "parser.cpp"
    break;

  case 40: // statements: statements statement
#line 220 "parser.y"
        {
            yystack_[1].value.as < std::vector<ASTNode*>* > ()->push_back(yystack_[0].value.as < ASTNode* > ());
            yylhs.value.as < std::vector<ASTNode*>* > () = yystack_[1].value.as < std::vector<ASTNode*>* > ();
        }
#line 1005 "parser.cpp"
    break;

  case 41: // expression: expression OR expression
#line 228 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new LogicalOpNode('O', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1013 "parser.cpp"
    break;

  case 42: // expression: NOT expression
#line 232 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new LogicalOpNode('N', yystack_[0].value.as < ASTNode* > (), nullptr);
        }
#line 1021 "parser.cpp"
    break;

  case 43: // expression: expression GT expression
#line 236 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ComparisonNode('G', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1029 "parser.cpp"
    break;

  case 44: // expression: expression LT expression
#line 240 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ComparisonNode('L', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1037 "parser.cpp"
    break;

  case 45: // expression: expression PLUS expression
#line 244 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArithmeticOpNode('+', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1045 "parser.cpp"
    break;

  case 46: // expression: expression MINUS expression
#line 248 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArithmeticOpNode('-', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1053 "parser.cpp"
    break;

  case 47: // expression: expression MULTIPLY expression
#line 252 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArithmeticOpNode('*', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1061 "parser.cpp"
    break;

  case 48: // expression: expression DIVIDE expression
#line 256 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArithmeticOpNode('/', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1069 "parser.cpp"
    break;

  case 49: // expression: expression MODULO expression
#line 260 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArithmeticOpNode('%', yystack_[2].value.as < ASTNode* > (), yystack_[0].value.as < ASTNode* > ());
        }
#line 1077 "parser.cpp"
    break;

  case 50: // expression: LPAREN expression RPAREN
#line 264 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = yystack_[1].value.as < ASTNode* > ();
        }
#line 1085 "parser.cpp"
    break;

  case 51: // expression: UNSIGNED_INT
#line 268 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new IntNode(yystack_[0].value.as < int > ());
        }
#line 1093 "parser.cpp"
    break;

  case 52: // expression: BOOL_CONST
#line 272 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new BoolNode(yystack_[0].value.as < bool > ());
        }
#line 1101 "parser.cpp"
    break;

  case 53: // expression: IDENTIFIER
#line 276 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new VariableNode(yystack_[0].value.as < std::string > ());
        }
#line 1109 "parser.cpp"
    break;

  case 54: // expression: array_access
#line 280 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = yystack_[0].value.as < ASTNode* > ();
        }
#line 1117 "parser.cpp"
    break;

  case 55: // array_access: IDENTIFIER LPAREN expressions RPAREN
#line 287 "parser.y"
        {
            yylhs.value.as < ASTNode* > () = new ArrayAccessNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ASTNode*>* > ());
        }
#line 1125 "parser.cpp"
    break;

  case 56: // expressions: expression
#line 294 "parser.y"
        {
            yylhs.value.as < std::vector<ASTNode*>* > () = new std::vector<ASTNode*>();
            yylhs.value.as < std::vector<ASTNode*>* > ()->push_back(yystack_[0].value.as < ASTNode* > ());
        }
#line 1134 "parser.cpp"
    break;

  case 57: // expressions: expressions COMMA expression
#line 299 "parser.y"
        {
            yystack_[2].value.as < std::vector<ASTNode*>* > ()->push_back(yystack_[0].value.as < ASTNode* > ());
            yylhs.value.as < std::vector<ASTNode*>* > () = yystack_[2].value.as < std::vector<ASTNode*>* > ();
        }
#line 1143 "parser.cpp"
    break;

  case 58: // expressions: %empty
#line 304 "parser.y"
        { yylhs.value.as < std::vector<ASTNode*>* > () = new std::vector<ASTNode*>(); }
#line 1149 "parser.cpp"
    break;

  case 59: // return_variables: LBRACKET variables RBRACKET
#line 309 "parser.y"
        { yylhs.value.as < std::vector<ASTNode*>* > () = yystack_[1].value.as < std::vector<ASTNode*>* > (); }
#line 1155 "parser.cpp"
    break;

  case 60: // return_variables: variables
#line 311 "parser.y"
        { yylhs.value.as < std::vector<ASTNode*>* > () = yystack_[0].value.as < std::vector<ASTNode*>* > (); }
#line 1161 "parser.cpp"
    break;

  case 61: // parameters: variables
#line 316 "parser.y"
        { yylhs.value.as < std::vector<ASTNode*>* > () = yystack_[0].value.as < std::vector<ASTNode*>* > (); }
#line 1167 "parser.cpp"
    break;

  case 62: // parameters: %empty
#line 318 "parser.y"
        { yylhs.value.as < std::vector<ASTNode*>* > () = new std::vector<ASTNode*>(); }
#line 1173 "parser.cpp"
    break;

  case 63: // variables: IDENTIFIER
#line 323 "parser.y"
        {
            yylhs.value.as < std::vector<ASTNode*>* > () = new std::vector<ASTNode*>();
            yylhs.value.as < std::vector<ASTNode*>* > ()->push_back(new VariableNode(yystack_[0].value.as < std::string > ()));
        }
#line 1182 "parser.cpp"
    break;

  case 64: // variables: variables COMMA IDENTIFIER
#line 328 "parser.y"
        {
            yystack_[2].value.as < std::vector<ASTNode*>* > ()->push_back(new VariableNode(yystack_[0].value.as < std::string > ()));
            yylhs.value.as < std::vector<ASTNode*>* > () = yystack_[2].value.as < std::vector<ASTNode*>* > ();
        }
#line 1191 "parser.cpp"
    break;

  case 65: // movement_operator: FORW
#line 336 "parser.y"
        { yylhs.value.as < ASTNode* > () = new MovementNode("FORW"); }
#line 1197 "parser.cpp"
    break;

  case 66: // movement_operator: BACK
#line 338 "parser.y"
        { yylhs.value.as < ASTNode* > () = new MovementNode("BACK"); }
#line 1203 "parser.cpp"
    break;

  case 67: // movement_operator: RIGHT_OP
#line 340 "parser.y"
        { yylhs.value.as < ASTNode* > () = new MovementNode("RIGHT"); }
#line 1209 "parser.cpp"
    break;

  case 68: // movement_operator: LEFT_OP
#line 342 "parser.y"
        { yylhs.value.as < ASTNode* > () = new MovementNode("LEFT"); }
#line 1215 "parser.cpp"
    break;

  case 69: // sensor_operator: GETF
#line 347 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("GETF"); }
#line 1221 "parser.cpp"
    break;

  case 70: // sensor_operator: GETB
#line 349 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("GETB"); }
#line 1227 "parser.cpp"
    break;

  case 71: // sensor_operator: GETR
#line 351 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("GETR"); }
#line 1233 "parser.cpp"
    break;

  case 72: // sensor_operator: GETL
#line 353 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("GETL"); }
#line 1239 "parser.cpp"
    break;

  case 73: // sensor_operator: PUSHF
#line 355 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("PUSHF"); }
#line 1245 "parser.cpp"
    break;

  case 74: // sensor_operator: PUSHB
#line 357 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("PUSHB"); }
#line 1251 "parser.cpp"
    break;

  case 75: // sensor_operator: PUSHR
#line 359 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("PUSHR"); }
#line 1257 "parser.cpp"
    break;

  case 76: // sensor_operator: PUSHL
#line 361 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("PUSHL"); }
#line 1263 "parser.cpp"
    break;

  case 77: // sensor_operator: UNDO
#line 363 "parser.y"
        { yylhs.value.as < ASTNode* > () = new SensorNode("UNDO"); }
#line 1269 "parser.cpp"
    break;


#line 1273 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  ParserClass::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  ParserClass::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char ParserClass::yypact_ninf_ = -123;

  const signed char ParserClass::yytable_ninf_ = -1;

  const short
  ParserClass::yypact_[] =
  {
    -123,    67,  -123,    -2,     0,  -123,     9,    10,    20,    30,
      31,    48,    49,    51,    65,    69,    70,    71,    -3,    77,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,    73,    50,    95,
     101,   102,    46,    46,  -123,    18,   118,   117,   119,   121,
     124,   127,   128,   129,   130,   131,   134,    46,    46,    46,
      46,    46,   120,   136,  -123,  -123,  -123,  -123,   133,    46,
      46,    66,  -123,   301,    61,  -123,  -123,  -123,  -123,  -123,
      46,    46,    46,    46,   132,   143,   144,   146,   167,   257,
     268,   279,   180,   150,  -123,    46,   290,  -123,  -123,    46,
      46,    46,    46,    46,    46,    46,    46,    46,   153,   193,
     206,   219,   232,    46,    46,    46,    46,  -123,    46,   137,
     162,  -123,     0,    96,  -123,    28,    28,  -123,  -123,  -123,
     312,    -6,    -6,   301,  -123,  -123,  -123,  -123,  -123,    19,
      25,    26,    40,   245,   162,   138,   168,    95,  -123,   170,
     173,   174,   181,  -123,  -123,   162,   162,  -123,  -123,  -123,
    -123,  -123,  -123
  };

  const signed char
  ParserClass::yydefact_[] =
  {
       2,     0,     1,    63,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     3,     8,     9,     4,     5,     6,     7,
      10,    11,    12,    13,    14,    15,    16,     0,     0,    60,
       0,     0,     0,    58,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    51,    52,    53,     0,
       0,     0,    54,    56,     0,    59,    38,    40,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    58,     0,    42,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,    58,    58,    58,    58,    28,     0,     0,
       0,    18,    62,     0,    50,    45,    46,    47,    48,    49,
      41,    43,    44,    57,    19,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,    33,     0,    61,    55,     0,
       0,     0,     0,    29,    32,     0,     0,    24,    25,    26,
      27,    34,    35
  };

  const short
  ParserClass::yypgoto_[] =
  {
    -123,  -123,   145,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -122,  -123,   -51,     1,  -102,
    -123,  -123,    -4,  -123,  -123
  };

  const unsigned char
  ParserClass::yydefgoto_[] =
  {
       0,     1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    56,    83,    82,    84,
      48,   156,    49,    50,    51
  };

  const unsigned char
  ParserClass::yytable_[] =
  {
      55,    81,    47,   133,    52,    54,    69,    53,   155,   109,
     110,   111,   112,   113,    57,    58,    98,    99,   100,   101,
     102,   149,   150,   151,   152,    59,    73,   117,   106,   107,
      85,   159,   164,   117,   117,    60,    61,   160,   161,   119,
     120,   121,   122,   171,   172,   111,   112,   113,   117,    76,
      77,    78,   162,    62,    63,    79,    64,    47,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     2,    80,   117,
      65,   118,     3,   108,    66,    67,    68,   153,     4,    71,
       5,   109,   110,   111,   112,   113,    70,     6,     7,   114,
     115,   116,    72,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    73,   117,    18,   158,    19,    74,    75,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     3,    88,   103,    89,    90,   157,     4,
      91,     5,    86,    92,    93,    94,    95,    96,     6,     7,
      97,   104,   105,   123,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   124,   125,    18,   126,    19,   132,
     144,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   127,     5,   154,   167,   166,   165,
     168,   169,   109,   110,   111,   112,   113,   131,   170,     0,
     114,   115,   116,     0,     0,   109,   110,   111,   112,   113,
     145,    87,     0,   114,   115,   116,     0,     0,   109,   110,
     111,   112,   113,   146,     0,     0,   114,   115,   116,     0,
       0,   109,   110,   111,   112,   113,   147,     0,     0,   114,
     115,   116,     0,     0,   109,   110,   111,   112,   113,   148,
       0,     0,   114,   115,   116,     0,     0,   109,   110,   111,
     112,   113,   163,     0,     0,   114,   115,   116,     0,     0,
     109,   110,   111,   112,   113,   128,     0,     0,   114,   115,
     116,     0,   109,   110,   111,   112,   113,     0,   129,     0,
     114,   115,   116,   109,   110,   111,   112,   113,     0,   130,
       0,   114,   115,   116,   109,   110,   111,   112,   113,     0,
     134,     0,   114,   115,   116,   109,   110,   111,   112,   113,
       0,     0,     0,   114,   115,   116,   109,   110,   111,   112,
     113,     0,     0,     0,   114,   115,   116,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   115,   116
  };

  const short
  ParserClass::yycheck_[] =
  {
       4,    52,     1,   105,     6,     5,     9,     9,   130,    15,
      16,    17,    18,    19,     5,     5,    67,    68,    69,    70,
      71,   123,   124,   125,   126,     5,     8,     8,    79,    80,
      12,    12,   154,     8,     8,     5,     5,    12,    12,    90,
      91,    92,    93,   165,   166,    17,    18,    19,     8,     3,
       4,     5,    12,     5,     5,     9,     5,    56,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,    22,     8,
       5,    10,     5,     7,     5,     5,     5,   128,    11,     6,
      13,    15,    16,    17,    18,    19,     9,    20,    21,    23,
      24,    25,    42,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     8,     8,    38,    10,    40,     7,     7,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     5,     7,     5,     7,     6,   132,    11,
       6,    13,    14,     6,     6,     6,     6,     6,    20,    21,
       6,     5,     9,    11,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    11,    11,    38,    11,    40,     9,
       7,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     7,    13,    39,     7,    10,    41,
       7,     7,    15,    16,    17,    18,    19,     7,     7,    -1,
      23,    24,    25,    -1,    -1,    15,    16,    17,    18,    19,
       7,    56,    -1,    23,    24,    25,    -1,    -1,    15,    16,
      17,    18,    19,     7,    -1,    -1,    23,    24,    25,    -1,
      -1,    15,    16,    17,    18,    19,     7,    -1,    -1,    23,
      24,    25,    -1,    -1,    15,    16,    17,    18,    19,     7,
      -1,    -1,    23,    24,    25,    -1,    -1,    15,    16,    17,
      18,    19,     7,    -1,    -1,    23,    24,    25,    -1,    -1,
      15,    16,    17,    18,    19,     8,    -1,    -1,    23,    24,
      25,    -1,    15,    16,    17,    18,    19,    -1,    10,    -1,
      23,    24,    25,    15,    16,    17,    18,    19,    -1,    10,
      -1,    23,    24,    25,    15,    16,    17,    18,    19,    -1,
      10,    -1,    23,    24,    25,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    25,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    25
  };

  const signed char
  ParserClass::yystos_[] =
  {
       0,    57,     0,     5,    11,    13,    20,    21,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    38,    40,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    74,    76,    78,
      79,    80,     6,     9,     5,    78,    72,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     9,
       9,     6,    42,     8,     7,     7,     3,     4,     5,     9,
      22,    73,    74,    73,    75,    12,    14,    58,     7,     7,
       6,     6,     6,     6,     6,     6,     6,     6,    73,    73,
      73,    73,    73,     5,     5,     9,    73,    73,     7,    15,
      16,    17,    18,    19,    23,    24,    25,     8,    10,    73,
      73,    73,    73,    11,    11,    11,    11,     7,     8,    10,
      10,     7,     9,    75,    10,    73,    73,    73,    73,    73,
      73,    73,    73,    73,     7,     7,     7,     7,     7,    75,
      75,    75,    75,    73,    39,    71,    77,    78,    10,    12,
      12,    12,    12,     7,    71,    41,    10,     7,     7,     7,
       7,    71,    71
  };

  const signed char
  ParserClass::yyr1_[] =
  {
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      65,    66,    67,    68,    68,    69,    70,    70,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    75,    75,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80
  };

  const signed char
  ParserClass::yyr2_[] =
  {
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     5,
       5,     5,     5,     5,     7,     7,     7,     7,     4,     6,
       3,     3,     6,     5,     7,     7,     2,     2,     3,     0,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     4,     1,     3,     0,     3,
       1,     1,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const ParserClass::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "UNSIGNED_INT",
  "BOOL_CONST", "IDENTIFIER", "ASSIGN", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "INC", "DEC", "NOT", "OR", "GT", "LT",
  "UINT", "BOOLEAN", "CUINT", "CBOOLEAN", "ARRAY1DBOOL", "ARRAY2DBOOL",
  "ARRAY1DUINT", "ARRAY2DUINT", "EXTEND1", "EXTEND2", "SIZE1", "SIZE2",
  "WHILE", "DO", "IF", "ELSE", "FUNCTION", "FORW", "BACK", "RIGHT_OP",
  "LEFT_OP", "GETF", "GETB", "GETR", "GETL", "PUSHF", "PUSHB", "PUSHR",
  "PUSHL", "UNDO", "$accept", "program", "statement", "assignment",
  "function_call", "variable_declaration", "constant_declaration",
  "array_declaration", "array_extension", "increment", "decrement", "loop",
  "conditional", "function_declaration", "robot_operation",
  "group_of_statements", "statements", "expression", "array_access",
  "expressions", "return_variables", "parameters", "variables",
  "movement_operator", "sensor_operator", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  ParserClass::yyrline_[] =
  {
       0,    63,    63,    67,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    91,    95,   102,
     109,   113,   120,   124,   131,   135,   139,   143,   150,   154,
     161,   168,   175,   182,   186,   193,   200,   202,   207,   216,
     219,   227,   231,   235,   239,   243,   247,   251,   255,   259,
     263,   267,   271,   275,   279,   286,   293,   298,   304,   308,
     310,   315,   318,   322,   327,   335,   337,   339,   341,   346,
     348,   350,   352,   354,   356,   358,   360,   362
  };

  void
  ParserClass::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  ParserClass::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 17 "parser.y"
} // ParserNS
#line 1725 "parser.cpp"

#line 366 "parser.y"


void yyerror(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
    exit(1);
}
