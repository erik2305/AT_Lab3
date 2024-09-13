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

using namespace std;

extern int yylex();
void yyerror(const char *s);

extern ASTNode *ast_root;


#line 57 "parser.cpp"


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

#line 18 "parser.y"
namespace Parser {
#line 136 "parser.cpp"

  /// Build a parser object.
  Parser::Parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: %empty
#line 60 "parser.y"
    {
        (yylhs.value.node) = nullptr;  // Set the program to null if there's no statement
    }
#line 594 "parser.cpp"
    break;

  case 3: // program: program statement
#line 64 "parser.y"
        {
            if ((yystack_[1].value.node)) {
                (yystack_[1].value.node)->addSibling((yystack_[0].value.node));
                (yylhs.value.node) = (yystack_[1].value.node);
            } else {
                (yylhs.value.node) = (yystack_[0].value.node);
            }
        }
#line 607 "parser.cpp"
    break;

  case 4: // statement: variable_declaration
#line 75 "parser.y"
    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 613 "parser.cpp"
    break;

  case 5: // statement: constant_declaration
#line 76 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 619 "parser.cpp"
    break;

  case 6: // statement: array_declaration
#line 77 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 625 "parser.cpp"
    break;

  case 7: // statement: array_extension
#line 78 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 631 "parser.cpp"
    break;

  case 8: // statement: assignment
#line 79 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 637 "parser.cpp"
    break;

  case 9: // statement: increment
#line 80 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 643 "parser.cpp"
    break;

  case 10: // statement: decrement
#line 81 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 649 "parser.cpp"
    break;

  case 11: // statement: loop
#line 82 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 655 "parser.cpp"
    break;

  case 12: // statement: conditional
#line 83 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 661 "parser.cpp"
    break;

  case 13: // statement: function_declaration
#line 84 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 667 "parser.cpp"
    break;

  case 14: // statement: function_call
#line 85 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 673 "parser.cpp"
    break;

  case 15: // statement: robot_operation
#line 86 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 679 "parser.cpp"
    break;

  case 16: // statement: group_of_statements
#line 87 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 685 "parser.cpp"
    break;

  case 17: // variable_declaration: UINT IDENTIFIER ASSIGN arithmetic_expression SEMICOLON
#line 92 "parser.y"
        {
            (yylhs.value.node) = new VarDeclarationNode((yystack_[3].value.id), VarType::UINT, (yystack_[1].value.node));
        }
#line 693 "parser.cpp"
    break;

  case 18: // variable_declaration: BOOLEAN IDENTIFIER ASSIGN logical_expression SEMICOLON
#line 96 "parser.y"
        {
            (yylhs.value.node) = new VarDeclarationNode((yystack_[3].value.id), VarType::BOOLEAN, (yystack_[1].value.node));
        }
#line 701 "parser.cpp"
    break;

  case 19: // constant_declaration: CUINT IDENTIFIER ASSIGN arithmetic_expression SEMICOLON
#line 103 "parser.y"
        {
            (yylhs.value.node) = new ConstDeclarationNode((yystack_[3].value.id), VarType::UINT, (yystack_[1].value.node));
        }
#line 709 "parser.cpp"
    break;

  case 20: // constant_declaration: CBOOLEAN IDENTIFIER ASSIGN logical_expression SEMICOLON
#line 107 "parser.y"
        {
            (yylhs.value.node) = new ConstDeclarationNode((yystack_[3].value.id), VarType::BOOLEAN, (yystack_[1].value.node));
        }
#line 717 "parser.cpp"
    break;

  case 21: // array_declaration: ARRAY1DBOOL IDENTIFIER ASSIGN LBRACKET logical_expression_list RBRACKET SEMICOLON
#line 114 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode((yystack_[5].value.id), VarType::BOOLEAN, 1, (yystack_[2].value.node_list));
        }
#line 725 "parser.cpp"
    break;

  case 22: // array_declaration: ARRAY2DBOOL IDENTIFIER ASSIGN LBRACKET logical_expression_matrix RBRACKET SEMICOLON
#line 118 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode((yystack_[5].value.id), VarType::BOOLEAN, 2, (yystack_[2].value.node_list));
        }
#line 733 "parser.cpp"
    break;

  case 23: // array_declaration: ARRAY1DUINT IDENTIFIER ASSIGN LBRACKET arithmetic_expression_list RBRACKET SEMICOLON
#line 122 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode((yystack_[5].value.id), VarType::UINT, 1, (yystack_[2].value.node_list));
        }
#line 741 "parser.cpp"
    break;

  case 24: // array_declaration: ARRAY2DUINT IDENTIFIER ASSIGN LBRACKET arithmetic_expression_matrix RBRACKET SEMICOLON
#line 126 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode((yystack_[5].value.id), VarType::UINT, 2, (yystack_[2].value.node_list));
        }
#line 749 "parser.cpp"
    break;

  case 25: // array_extension: EXTEND1 IDENTIFIER arithmetic_expression SEMICOLON
#line 133 "parser.y"
        {
            (yylhs.value.node) = new ArrayExtensionNode((yystack_[2].value.id), 1, (yystack_[1].value.node));
        }
#line 757 "parser.cpp"
    break;

  case 26: // array_extension: EXTEND2 IDENTIFIER arithmetic_expression arithmetic_expression SEMICOLON
#line 137 "parser.y"
        {
            (yylhs.value.node) = new ArrayExtensionNode((yystack_[3].value.id), 2, (yystack_[2].value.node), (yystack_[1].value.node));
        }
#line 765 "parser.cpp"
    break;

  case 27: // assignment: IDENTIFIER ASSIGN expression SEMICOLON
#line 144 "parser.y"
        {
            (yylhs.value.node) = new AssignmentNode((yystack_[3].value.id), (yystack_[1].value.node));
        }
#line 773 "parser.cpp"
    break;

  case 28: // assignment: array_access ASSIGN expression SEMICOLON
#line 148 "parser.y"
        {
            (yylhs.value.node) = new ArrayAssignmentNode((yystack_[3].value.node), (yystack_[1].value.node));
        }
#line 781 "parser.cpp"
    break;

  case 29: // increment: INC IDENTIFIER SEMICOLON
#line 155 "parser.y"
        {
            (yylhs.value.node) = new IncDecNode((yystack_[1].value.id), 1);
        }
#line 789 "parser.cpp"
    break;

  case 30: // decrement: DEC IDENTIFIER SEMICOLON
#line 162 "parser.y"
        {
            (yylhs.value.node) = new IncDecNode((yystack_[1].value.id), -1);
        }
#line 797 "parser.cpp"
    break;

  case 31: // loop: WHILE LPAREN logical_expression RPAREN DO group_of_statements
#line 169 "parser.y"
        {
            (yylhs.value.node) = new WhileNode((yystack_[3].value.node), (yystack_[0].value.node));
        }
#line 805 "parser.cpp"
    break;

  case 32: // conditional: IF LPAREN logical_expression RPAREN group_of_statements
#line 176 "parser.y"
        {
            (yylhs.value.node) = new IfNode((yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 813 "parser.cpp"
    break;

  case 33: // conditional: IF LPAREN logical_expression RPAREN group_of_statements ELSE group_of_statements
#line 180 "parser.y"
        {
            (yylhs.value.node) = new IfNode((yystack_[4].value.node), (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 821 "parser.cpp"
    break;

  case 34: // function_declaration: return_variables FUNCTION IDENTIFIER LPAREN parameters RPAREN group_of_statements
#line 187 "parser.y"
        {
            (yylhs.value.node) = new FunctionDeclarationNode((yystack_[4].value.id), (yystack_[6].value.node_list), (yystack_[2].value.node_list), (yystack_[0].value.node));
        }
#line 829 "parser.cpp"
    break;

  case 35: // function_call: variables ASSIGN IDENTIFIER LPAREN expressions RPAREN SEMICOLON
#line 194 "parser.y"
        {
            (yylhs.value.node) = new FunctionCallNode((yystack_[4].value.id), (yystack_[2].value.node_list), (yystack_[6].value.node_list));
        }
#line 837 "parser.cpp"
    break;

  case 36: // function_call: IDENTIFIER LPAREN expressions RPAREN SEMICOLON
#line 198 "parser.y"
        {
            (yylhs.value.node) = new FunctionCallNode((yystack_[4].value.id), (yystack_[2].value.node_list));
        }
#line 845 "parser.cpp"
    break;

  case 37: // robot_operation: movement_operator SEMICOLON
#line 205 "parser.y"
        {
            (yylhs.value.node) = new RobotOperationNode((yystack_[1].value.node));
        }
#line 853 "parser.cpp"
    break;

  case 38: // robot_operation: sensor_operator SEMICOLON
#line 209 "parser.y"
        {
            (yylhs.value.node) = new RobotOperationNode((yystack_[1].value.node));
        }
#line 861 "parser.cpp"
    break;

  case 39: // group_of_statements: LBRACE statements RBRACE
#line 216 "parser.y"
        {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 869 "parser.cpp"
    break;

  case 40: // statements: %empty
#line 223 "parser.y"
        {
            (yylhs.value.node) = nullptr;
        }
#line 877 "parser.cpp"
    break;

  case 41: // statements: statements statement
#line 227 "parser.y"
        {
            if ((yystack_[1].value.node)) {
                (yystack_[1].value.node)->addSibling((yystack_[0].value.node));
                (yylhs.value.node) = (yystack_[1].value.node);
            } else {
                (yylhs.value.node) = (yystack_[0].value.node);
            }
        }
#line 890 "parser.cpp"
    break;

  case 42: // expression: arithmetic_expression
#line 239 "parser.y"
        { (yylhs.value.node) = (yystack_[0].value.node); }
#line 896 "parser.cpp"
    break;

  case 43: // expression: logical_expression
#line 241 "parser.y"
        { (yylhs.value.node) = (yystack_[0].value.node); }
#line 902 "parser.cpp"
    break;

  case 44: // arithmetic_expression: arithmetic_expression PLUS arithmetic_expression
#line 246 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('+', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 910 "parser.cpp"
    break;

  case 45: // arithmetic_expression: arithmetic_expression MINUS arithmetic_expression
#line 250 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('-', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 918 "parser.cpp"
    break;

  case 46: // arithmetic_expression: arithmetic_expression MULTIPLY arithmetic_expression
#line 254 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('*', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 926 "parser.cpp"
    break;

  case 47: // arithmetic_expression: arithmetic_expression DIVIDE arithmetic_expression
#line 258 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('/', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 934 "parser.cpp"
    break;

  case 48: // arithmetic_expression: arithmetic_expression MODULO arithmetic_expression
#line 262 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('%', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 942 "parser.cpp"
    break;

  case 49: // arithmetic_expression: LPAREN arithmetic_expression RPAREN
#line 266 "parser.y"
        {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 950 "parser.cpp"
    break;

  case 50: // arithmetic_expression: UNSIGNED_INT
#line 270 "parser.y"
        {
            (yylhs.value.node) = new IntNode((yystack_[0].value.int_val));
        }
#line 958 "parser.cpp"
    break;

  case 51: // arithmetic_expression: IDENTIFIER
#line 274 "parser.y"
        {
            (yylhs.value.node) = new VariableNode((yystack_[0].value.id));
        }
#line 966 "parser.cpp"
    break;

  case 52: // arithmetic_expression: function_call
#line 278 "parser.y"
        {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 974 "parser.cpp"
    break;

  case 53: // arithmetic_expression: array_access
#line 282 "parser.y"
        {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 982 "parser.cpp"
    break;

  case 54: // logical_expression: logical_expression OR logical_expression
#line 289 "parser.y"
        {
            (yylhs.value.node) = new LogicalOpNode('O', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 990 "parser.cpp"
    break;

  case 55: // logical_expression: NOT logical_expression
#line 293 "parser.y"
        {
            (yylhs.value.node) = new LogicalOpNode('N', (yystack_[0].value.node));
        }
#line 998 "parser.cpp"
    break;

  case 56: // logical_expression: comparison
#line 297 "parser.y"
        {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 1006 "parser.cpp"
    break;

  case 57: // logical_expression: BOOL_CONST
#line 301 "parser.y"
        {
            (yylhs.value.node) = new BoolNode((yystack_[0].value.bool_val));
        }
#line 1014 "parser.cpp"
    break;

  case 58: // logical_expression: IDENTIFIER
#line 305 "parser.y"
        {
            (yylhs.value.node) = new VariableNode((yystack_[0].value.id));
        }
#line 1022 "parser.cpp"
    break;

  case 59: // logical_expression: function_call
#line 309 "parser.y"
        {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 1030 "parser.cpp"
    break;

  case 60: // logical_expression: array_access
#line 313 "parser.y"
        {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 1038 "parser.cpp"
    break;

  case 61: // comparison: arithmetic_expression GT arithmetic_expression
#line 320 "parser.y"
        {
            (yylhs.value.node) = new ComparisonNode('G', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 1046 "parser.cpp"
    break;

  case 62: // comparison: arithmetic_expression LT arithmetic_expression
#line 324 "parser.y"
        {
            (yylhs.value.node) = new ComparisonNode('L', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 1054 "parser.cpp"
    break;

  case 63: // array_access: IDENTIFIER LPAREN arithmetic_expression_list RPAREN
#line 331 "parser.y"
        {
            (yylhs.value.node) = new ArrayAccessNode((yystack_[3].value.id), (yystack_[1].value.node_list));
        }
#line 1062 "parser.cpp"
    break;

  case 64: // arithmetic_expression_list: arithmetic_expression
#line 338 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
            (yylhs.value.node_list)->push_back((yystack_[0].value.node));
        }
#line 1071 "parser.cpp"
    break;

  case 65: // arithmetic_expression_list: arithmetic_expression_list COMMA arithmetic_expression
#line 343 "parser.y"
        {
            (yystack_[2].value.node_list)->push_back((yystack_[0].value.node));
            (yylhs.value.node_list) = (yystack_[2].value.node_list);
        }
#line 1080 "parser.cpp"
    break;

  case 66: // logical_expression_list: logical_expression
#line 351 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
            (yylhs.value.node_list)->push_back((yystack_[0].value.node));
        }
#line 1089 "parser.cpp"
    break;

  case 67: // logical_expression_list: logical_expression_list COMMA logical_expression
#line 356 "parser.y"
        {
            (yystack_[2].value.node_list)->push_back((yystack_[0].value.node));
            (yylhs.value.node_list) = (yystack_[2].value.node_list);
        }
#line 1098 "parser.cpp"
    break;

  case 68: // logical_expression_matrix: logical_expression_list
#line 364 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
            (yylhs.value.node_list)->push_back(new MatrixRowNode((yystack_[0].value.node_list)));
        }
#line 1107 "parser.cpp"
    break;

  case 69: // logical_expression_matrix: logical_expression_matrix SEMICOLON logical_expression_list
#line 369 "parser.y"
        {
            (yystack_[2].value.node_list)->push_back(new MatrixRowNode((yystack_[0].value.node_list)));
            (yylhs.value.node_list) = (yystack_[2].value.node_list);
        }
#line 1116 "parser.cpp"
    break;

  case 70: // arithmetic_expression_matrix: arithmetic_expression_list
#line 377 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
            (yylhs.value.node_list)->push_back(new MatrixRowNode((yystack_[0].value.node_list)));
        }
#line 1125 "parser.cpp"
    break;

  case 71: // arithmetic_expression_matrix: arithmetic_expression_matrix SEMICOLON arithmetic_expression_list
#line 382 "parser.y"
        {
            (yystack_[2].value.node_list)->push_back(new MatrixRowNode((yystack_[0].value.node_list)));
            (yylhs.value.node_list) = (yystack_[2].value.node_list);
        }
#line 1134 "parser.cpp"
    break;

  case 72: // return_variables: LBRACKET variables RBRACKET
#line 390 "parser.y"
        { (yylhs.value.node_list) = (yystack_[1].value.node_list); }
#line 1140 "parser.cpp"
    break;

  case 73: // return_variables: variables
#line 392 "parser.y"
        { (yylhs.value.node_list) = (yystack_[0].value.node_list); }
#line 1146 "parser.cpp"
    break;

  case 74: // parameters: variables
#line 397 "parser.y"
        { (yylhs.value.node_list) = (yystack_[0].value.node_list); }
#line 1152 "parser.cpp"
    break;

  case 75: // parameters: %empty
#line 399 "parser.y"
        { (yylhs.value.node_list) = new std::vector<ASTNode*>(); }
#line 1158 "parser.cpp"
    break;

  case 76: // variables: IDENTIFIER
#line 404 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
            (yylhs.value.node_list)->push_back(new VariableNode((yystack_[0].value.id)));
        }
#line 1167 "parser.cpp"
    break;

  case 77: // variables: variables COMMA IDENTIFIER
#line 409 "parser.y"
        {
            (yystack_[2].value.node_list)->push_back(new VariableNode((yystack_[0].value.id)));
            (yylhs.value.node_list) = (yystack_[2].value.node_list);
        }
#line 1176 "parser.cpp"
    break;

  case 78: // expressions: expression
#line 417 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
            (yylhs.value.node_list)->push_back((yystack_[0].value.node));
        }
#line 1185 "parser.cpp"
    break;

  case 79: // expressions: expressions COMMA expression
#line 422 "parser.y"
        {
            (yystack_[2].value.node_list)->push_back((yystack_[0].value.node));
            (yylhs.value.node_list) = (yystack_[2].value.node_list);
        }
#line 1194 "parser.cpp"
    break;

  case 80: // expressions: %empty
#line 427 "parser.y"
        { (yylhs.value.node_list) = new std::vector<ASTNode*>(); }
#line 1200 "parser.cpp"
    break;

  case 81: // movement_operator: FORW
#line 432 "parser.y"
        { (yylhs.value.node) = new MovementNode("FORW"); }
#line 1206 "parser.cpp"
    break;

  case 82: // movement_operator: BACK
#line 434 "parser.y"
        { (yylhs.value.node) = new MovementNode("BACK"); }
#line 1212 "parser.cpp"
    break;

  case 83: // movement_operator: RIGHT_OP
#line 436 "parser.y"
        { (yylhs.value.node) = new MovementNode("RIGHT"); }
#line 1218 "parser.cpp"
    break;

  case 84: // movement_operator: LEFT_OP
#line 438 "parser.y"
        { (yylhs.value.node) = new MovementNode("LEFT"); }
#line 1224 "parser.cpp"
    break;

  case 85: // sensor_operator: GETF
#line 443 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETF"); }
#line 1230 "parser.cpp"
    break;

  case 86: // sensor_operator: GETB
#line 445 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETB"); }
#line 1236 "parser.cpp"
    break;

  case 87: // sensor_operator: GETR
#line 447 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETR"); }
#line 1242 "parser.cpp"
    break;

  case 88: // sensor_operator: GETL
#line 449 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETL"); }
#line 1248 "parser.cpp"
    break;

  case 89: // sensor_operator: PUSHF
#line 451 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHF"); }
#line 1254 "parser.cpp"
    break;

  case 90: // sensor_operator: PUSHB
#line 453 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHB"); }
#line 1260 "parser.cpp"
    break;

  case 91: // sensor_operator: PUSHR
#line 455 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHR"); }
#line 1266 "parser.cpp"
    break;

  case 92: // sensor_operator: PUSHL
#line 457 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHL"); }
#line 1272 "parser.cpp"
    break;

  case 93: // sensor_operator: UNDO
#line 459 "parser.y"
        { (yylhs.value.node) = new SensorNode("UNDO"); }
#line 1278 "parser.cpp"
    break;


#line 1282 "parser.cpp"

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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short Parser::yypact_ninf_ = -138;

  const signed char Parser::yytable_ninf_ = -77;

  const short
  Parser::yypact_[] =
  {
    -138,   190,  -138,   117,    -4,  -138,     3,     6,    62,    86,
     108,   128,   129,   138,   139,   140,   148,   149,    11,    88,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   151,    70,    40,
     153,   154,    12,    12,  -138,   106,   241,   160,   161,   152,
     163,   175,   177,   179,   180,   181,   185,    30,    30,    12,
      12,    12,   150,   187,   188,  -138,  -138,  -138,  -138,    18,
      30,    12,    14,   191,   189,   171,  -138,    17,    40,  -138,
     189,    51,    69,  -138,  -138,  -138,  -138,  -138,    30,    12,
      30,    12,   186,   198,   201,   204,   122,  -138,    47,  -138,
     147,   189,     8,     9,   192,   193,   217,  -138,   287,  -138,
    -138,    30,    30,    30,    30,    30,    30,    30,    12,    30,
    -138,    12,   220,    71,     5,    77,    15,    12,    12,    30,
      30,  -138,    92,   214,   216,  -138,    -4,    12,  -138,   121,
     121,  -138,  -138,  -138,   232,   232,  -138,   232,  -138,  -138,
    -138,  -138,  -138,  -138,   171,   107,   223,    35,   232,   113,
     248,    64,  -138,   216,   159,   247,   250,    96,    12,   252,
      12,   253,   256,    30,   257,  -138,   216,   216,   258,   171,
    -138,   223,  -138,  -138,   248,  -138,  -138,  -138,  -138
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     1,    76,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,    73,
       0,     0,     0,    80,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    50,    57,    51,
       0,     0,    52,     0,    42,    43,    56,    53,     0,    78,
      42,     0,     0,    72,    39,    41,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,     0,    53,
       0,     0,     0,     0,     0,     0,     0,    77,     0,    55,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    28,    75,    80,    49,    44,
      45,    46,    47,    48,    61,    62,    54,    65,    79,    36,
      17,    18,    19,    20,    66,     0,    68,     0,    64,     0,
      70,     0,    26,     0,    32,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,    67,
      21,    69,    22,    23,    71,    24,    33,    34,    35
  };

  const short
  Parser::yypgoto_[] =
  {
    -138,  -138,   210,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,    -1,  -138,  -137,  -138,   -48,    49,   -56,
    -138,     4,  -130,  -136,  -138,  -138,  -138,  -138,     2,   130,
    -138,  -138
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   107,    45,    46,    56,    89,   111,    85,
      86,   109,    91,   165,   167,   171,    48,   175,    88,    92,
      50,    51
  };

  const short
  Parser::yytable_[] =
  {
      44,    54,   166,    49,    83,    47,    55,   174,    57,   169,
     170,    58,   161,   112,   113,    77,    78,    79,   143,   144,
      69,    80,   163,   114,   -76,   119,   -59,    53,   128,   -60,
     -58,   128,   128,    77,    81,   106,   185,   -59,   128,    80,
     -60,   -58,   180,   134,   191,   136,    73,   181,    74,   196,
     197,    82,    82,   194,   141,    44,    87,    87,    49,   129,
      47,   130,   121,   122,   123,   124,   125,    59,    82,    82,
      82,   183,   156,    87,    87,    87,   184,   131,   160,   132,
      82,   164,   164,   158,   162,    87,   121,   122,   123,   124,
     125,    60,   121,   122,   123,   124,   125,    70,    82,   172,
      82,    84,    90,    87,   131,    87,   188,   121,   122,   123,
     124,   125,    72,    61,    74,   178,   108,   110,    93,   179,
      84,   129,   189,    52,   164,   182,    53,    82,   -76,   118,
      82,    53,    87,    62,    63,    87,    82,    82,   123,   124,
     125,    87,    87,    64,    65,    66,    82,   133,   176,   135,
      77,    87,   106,    67,    68,   115,    80,    71,    98,   142,
      75,    76,   121,   122,   123,   124,   125,    96,    97,    99,
     149,   150,   151,   152,   153,   154,   155,    82,   157,    82,
      84,   100,    87,   101,    87,   102,   103,   104,   168,   168,
       2,   105,   116,   117,   128,     3,    84,   137,   120,   145,
     186,     4,   146,     5,   121,   122,   123,   124,   125,   138,
       6,     7,   139,   126,   127,   140,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   147,   159,    18,     5,
      19,   178,   168,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     3,   121,   122,   123,
     124,   125,     4,   173,     5,    94,   129,   187,    74,   190,
     192,     6,     7,   193,   195,   198,    95,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   177,     0,    18,
       0,    19,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   148,     0,     0,
       0,     0,   121,   122,   123,   124,   125
  };

  const short
  Parser::yycheck_[] =
  {
       1,     5,   138,     1,    52,     1,     4,   144,     5,   139,
     140,     5,     7,    69,    70,     3,     4,     5,    10,    10,
       9,     9,     7,    71,     6,    81,    12,     9,    23,    12,
      12,    23,    23,     3,    22,     5,   173,    23,    23,     9,
      23,    23,     7,    99,   180,   101,     6,    12,     8,   186,
     187,    52,    53,   183,     7,    56,    52,    53,    56,     8,
      56,    10,    15,    16,    17,    18,    19,     5,    69,    70,
      71,     7,   128,    69,    70,    71,    12,     8,     7,    10,
      81,   137,   138,   131,     7,    81,    15,    16,    17,    18,
      19,     5,    15,    16,    17,    18,    19,     9,    99,     7,
     101,    52,    53,    99,     8,   101,    10,    15,    16,    17,
      18,    19,    42,     5,     8,     8,    67,    68,    12,    12,
      71,     8,   178,     6,   180,    12,     9,   128,     6,    80,
     131,     9,   128,     5,     5,   131,   137,   138,    17,    18,
      19,   137,   138,     5,     5,     5,   147,    98,   146,   100,
       3,   147,     5,     5,     5,     5,     9,     6,     6,   110,
       7,     7,    15,    16,    17,    18,    19,     7,     7,     6,
     121,   122,   123,   124,   125,   126,   127,   178,   129,   180,
     131,     6,   178,     6,   180,     6,     6,     6,   139,   140,
       0,     6,     5,     5,    23,     5,   147,    11,     7,     7,
      41,    11,     9,    13,    15,    16,    17,    18,    19,    11,
      20,    21,    11,    24,    25,    11,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     9,     7,    38,    13,
      40,     8,   183,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     5,    15,    16,    17,
      18,    19,    11,    39,    13,    14,     8,    10,     8,     7,
       7,    20,    21,     7,     7,     7,    56,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   147,    -1,    38,
      -1,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    57,     0,     5,    11,    13,    20,    21,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    38,    40,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    77,    82,    84,
      86,    87,     6,     9,     5,    84,    72,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     9,
       9,     6,    42,     6,     8,     7,     7,     3,     4,     5,
       9,    22,    69,    73,    74,    75,    76,    77,    84,    73,
      74,    78,    85,    12,    14,    58,     7,     7,     6,     6,
       6,     6,     6,     6,     6,     6,     5,    69,    74,    77,
      74,    74,    75,    75,    73,     5,     5,     5,    74,    75,
       7,    15,    16,    17,    18,    19,    24,    25,    23,     8,
      10,     8,    10,    74,    75,    74,    75,    11,    11,    11,
      11,     7,    74,    10,    10,     7,     9,     9,    10,    74,
      74,    74,    74,    74,    74,    74,    75,    74,    73,     7,
       7,     7,     7,     7,    75,    79,    79,    80,    74,    78,
      78,    81,     7,    39,    71,    83,    84,    85,     8,    12,
       7,    12,    12,     7,    12,    71,    41,    10,    10,    75,
       7,    79,     7,     7,    78,     7,    71,    71,     7
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     7,     7,     7,     7,     4,     5,     4,     4,     3,
       3,     6,     5,     7,     7,     7,     5,     2,     2,     3,
       0,     2,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     3,     3,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     1,     0,     1,     3,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "UNSIGNED_INT",
  "BOOL_CONST", "IDENTIFIER", "ASSIGN", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "INC", "DEC", "NOT", "OR", "GT", "LT",
  "UINT", "BOOLEAN", "CUINT", "CBOOLEAN", "ARRAY1DBOOL", "ARRAY2DBOOL",
  "ARRAY1DUINT", "ARRAY2DUINT", "EXTEND1", "EXTEND2", "SIZE1", "SIZE2",
  "WHILE", "DO", "IF", "ELSE", "FUNCTION", "FORW", "BACK", "RIGHT_OP",
  "LEFT_OP", "GETF", "GETB", "GETR", "GETL", "PUSHF", "PUSHB", "PUSHR",
  "PUSHL", "UNDO", "$accept", "program", "statement",
  "variable_declaration", "constant_declaration", "array_declaration",
  "array_extension", "assignment", "increment", "decrement", "loop",
  "conditional", "function_declaration", "function_call",
  "robot_operation", "group_of_statements", "statements", "expression",
  "arithmetic_expression", "logical_expression", "comparison",
  "array_access", "arithmetic_expression_list", "logical_expression_list",
  "logical_expression_matrix", "arithmetic_expression_matrix",
  "return_variables", "parameters", "variables", "expressions",
  "movement_operator", "sensor_operator", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    60,    60,    63,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    91,    95,   102,
     106,   113,   117,   121,   125,   132,   136,   143,   147,   154,
     161,   168,   175,   179,   186,   193,   197,   204,   208,   215,
     223,   226,   238,   240,   245,   249,   253,   257,   261,   265,
     269,   273,   277,   281,   288,   292,   296,   300,   304,   308,
     312,   319,   323,   330,   337,   342,   350,   355,   363,   368,
     376,   381,   389,   391,   396,   399,   403,   408,   416,   421,
     427,   431,   433,   435,   437,   442,   444,   446,   448,   450,
     452,   454,   456,   458
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
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

#line 18 "parser.y"
} // Parser
#line 1797 "parser.cpp"

#line 462 "parser.y"


void yyerror(const char *s) {
    std::cerr << "Error: " << s << std::endl;
    exit(1);
}
