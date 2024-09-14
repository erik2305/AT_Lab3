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

// Declare yylex with the correct signature expected by Bison
int yylex(Parser::semantic_type *yylval, Parser::location_type &loc);

// Update yyerror to match Bison's expectations
void yyerror(Parser::context_type& context, const char *s);

extern ASTNode *ast_root;

#line 59 "parser.cpp"


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

#line 21 "parser.y"
namespace Parser {
#line 138 "parser.cpp"

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
#line 79 "parser.y"
        {
            (yylhs.value.node) = new BlockNode(new std::vector<ASTNode*>());
        }
#line 596 "parser.cpp"
    break;

  case 3: // program: program statement
#line 83 "parser.y"
        {
            static_cast<BlockNode*>((yystack_[1].value.node))->addStatement((yystack_[0].value.node));
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 605 "parser.cpp"
    break;

  case 4: // statement: variable_declaration
#line 90 "parser.y"
    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 611 "parser.cpp"
    break;

  case 5: // statement: constant_declaration
#line 91 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 617 "parser.cpp"
    break;

  case 6: // statement: array_declaration
#line 92 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 623 "parser.cpp"
    break;

  case 7: // statement: array_extension
#line 93 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 629 "parser.cpp"
    break;

  case 8: // statement: assignment
#line 94 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 635 "parser.cpp"
    break;

  case 9: // statement: function_call
#line 95 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 641 "parser.cpp"
    break;

  case 10: // statement: increment
#line 96 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 647 "parser.cpp"
    break;

  case 11: // statement: decrement
#line 97 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 653 "parser.cpp"
    break;

  case 12: // statement: loop
#line 98 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 659 "parser.cpp"
    break;

  case 13: // statement: conditional
#line 99 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 665 "parser.cpp"
    break;

  case 14: // statement: function_declaration
#line 100 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 671 "parser.cpp"
    break;

  case 15: // statement: robot_operation
#line 101 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 677 "parser.cpp"
    break;

  case 16: // statement: group_of_statements
#line 102 "parser.y"
      { (yylhs.value.node) = (yystack_[0].value.node); }
#line 683 "parser.cpp"
    break;

  case 17: // assignment: IDENTIFIER ASSIGN expression SEMICOLON
#line 107 "parser.y"
        {
            (yylhs.value.node) = new AssignmentNode(std::string((yystack_[3].value.id)), (yystack_[1].value.node));
        }
#line 691 "parser.cpp"
    break;

  case 18: // assignment: array_access ASSIGN expression SEMICOLON
#line 111 "parser.y"
        {
            (yylhs.value.node) = new ArrayAssignmentNode((yystack_[3].value.node), (yystack_[1].value.node));
        }
#line 699 "parser.cpp"
    break;

  case 19: // function_call: IDENTIFIER LPAREN expressions RPAREN SEMICOLON
#line 118 "parser.y"
        {
            (yylhs.value.node) = new FunctionCallNode(std::string((yystack_[4].value.id)), (yystack_[2].value.expr_list));
        }
#line 707 "parser.cpp"
    break;

  case 20: // variable_declaration: UINT IDENTIFIER ASSIGN expression SEMICOLON
#line 125 "parser.y"
        {
            (yylhs.value.node) = new VarDeclarationNode(std::string((yystack_[3].value.id)), VarType::UINT, (yystack_[1].value.node));
        }
#line 715 "parser.cpp"
    break;

  case 21: // variable_declaration: BOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
#line 129 "parser.y"
        {
            (yylhs.value.node) = new VarDeclarationNode(std::string((yystack_[3].value.id)), VarType::BOOLEAN, (yystack_[1].value.node));
        }
#line 723 "parser.cpp"
    break;

  case 22: // constant_declaration: CUINT IDENTIFIER ASSIGN expression SEMICOLON
#line 136 "parser.y"
        {
            (yylhs.value.node) = new ConstDeclarationNode(std::string((yystack_[3].value.id)), VarType::UINT, (yystack_[1].value.node));
        }
#line 731 "parser.cpp"
    break;

  case 23: // constant_declaration: CBOOLEAN IDENTIFIER ASSIGN expression SEMICOLON
#line 140 "parser.y"
        {
            (yylhs.value.node) = new ConstDeclarationNode(std::string((yystack_[3].value.id)), VarType::BOOLEAN, (yystack_[1].value.node));
        }
#line 739 "parser.cpp"
    break;

  case 24: // array_declaration: ARRAY1DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 147 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode(std::string((yystack_[5].value.id)), VarType::BOOLEAN, 1, (yystack_[2].value.expr_list));
        }
#line 747 "parser.cpp"
    break;

  case 25: // array_declaration: ARRAY2DBOOL IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 151 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode(std::string((yystack_[5].value.id)), VarType::BOOLEAN, 2, (yystack_[2].value.expr_list));
        }
#line 755 "parser.cpp"
    break;

  case 26: // array_declaration: ARRAY1DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 155 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode(std::string((yystack_[5].value.id)), VarType::UINT, 1, (yystack_[2].value.expr_list));
        }
#line 763 "parser.cpp"
    break;

  case 27: // array_declaration: ARRAY2DUINT IDENTIFIER ASSIGN LBRACKET expressions RBRACKET SEMICOLON
#line 159 "parser.y"
        {
            (yylhs.value.node) = new ArrayDeclarationNode(std::string((yystack_[5].value.id)), VarType::UINT, 2, (yystack_[2].value.expr_list));
        }
#line 771 "parser.cpp"
    break;

  case 28: // array_extension: EXTEND1 IDENTIFIER expression SEMICOLON
#line 166 "parser.y"
        {
            (yylhs.value.node) = new ArrayExtensionNode(std::string((yystack_[2].value.id)), 1, (yystack_[1].value.node));
        }
#line 779 "parser.cpp"
    break;

  case 29: // array_extension: EXTEND2 IDENTIFIER expression COMMA expression SEMICOLON
#line 170 "parser.y"
        {
            (yylhs.value.node) = new ArrayExtensionNode(std::string((yystack_[4].value.id)), 2, (yystack_[3].value.node), (yystack_[1].value.node));
        }
#line 787 "parser.cpp"
    break;

  case 30: // increment: INC IDENTIFIER SEMICOLON
#line 177 "parser.y"
        {
            (yylhs.value.node) = new IncDecNode(std::string((yystack_[1].value.id)), 1);
        }
#line 795 "parser.cpp"
    break;

  case 31: // decrement: DEC IDENTIFIER SEMICOLON
#line 184 "parser.y"
        {
            (yylhs.value.node) = new IncDecNode(std::string((yystack_[1].value.id)), -1);
        }
#line 803 "parser.cpp"
    break;

  case 32: // loop: WHILE LPAREN expression RPAREN DO group_of_statements
#line 191 "parser.y"
        {
            (yylhs.value.node) = new WhileNode((yystack_[3].value.node), (yystack_[0].value.node));
        }
#line 811 "parser.cpp"
    break;

  case 33: // conditional: IF LPAREN expression RPAREN group_of_statements
#line 198 "parser.y"
        {
            (yylhs.value.node) = new IfNode((yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 819 "parser.cpp"
    break;

  case 34: // conditional: IF LPAREN expression RPAREN group_of_statements ELSE group_of_statements
#line 202 "parser.y"
        {
            (yylhs.value.node) = new IfNode((yystack_[4].value.node), (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 827 "parser.cpp"
    break;

  case 35: // function_declaration: return_variables FUNCTION IDENTIFIER LPAREN parameters RPAREN group_of_statements
#line 209 "parser.y"
        {
            (yylhs.value.node) = new FunctionDeclarationNode(std::string((yystack_[4].value.id)), (yystack_[6].value.var_list), (yystack_[2].value.var_list), (yystack_[0].value.node));
        }
#line 835 "parser.cpp"
    break;

  case 36: // robot_operation: movement_operator SEMICOLON
#line 216 "parser.y"
        { (yylhs.value.node) = new RobotOperationNode((yystack_[1].value.node)); }
#line 841 "parser.cpp"
    break;

  case 37: // robot_operation: sensor_operator SEMICOLON
#line 218 "parser.y"
        { (yylhs.value.node) = new RobotOperationNode((yystack_[1].value.node)); }
#line 847 "parser.cpp"
    break;

  case 38: // group_of_statements: LBRACE statements RBRACE
#line 223 "parser.y"
        {
            (yylhs.value.node) = new BlockNode((yystack_[1].value.node_list));
            delete (yystack_[1].value.node_list);  // Clean up the vector as it's now encapsulated within BlockNode
        }
#line 856 "parser.cpp"
    break;

  case 39: // statements: %empty
#line 231 "parser.y"
        {
            (yylhs.value.node_list) = new std::vector<ASTNode*>();
        }
#line 864 "parser.cpp"
    break;

  case 40: // statements: statements statement
#line 235 "parser.y"
        {
            (yystack_[1].value.node_list)->push_back((yystack_[0].value.node));
            (yylhs.value.node_list) = (yystack_[1].value.node_list);
        }
#line 873 "parser.cpp"
    break;

  case 41: // expression: expression OR expression
#line 243 "parser.y"
        {
            (yylhs.value.node) = new LogicalOpNode('O', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 881 "parser.cpp"
    break;

  case 42: // expression: NOT expression
#line 247 "parser.y"
        {
            (yylhs.value.node) = new LogicalOpNode('N', (yystack_[0].value.node));
        }
#line 889 "parser.cpp"
    break;

  case 43: // expression: expression GT expression
#line 251 "parser.y"
        {
            (yylhs.value.node) = new ComparisonNode('G', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 897 "parser.cpp"
    break;

  case 44: // expression: expression LT expression
#line 255 "parser.y"
        {
            (yylhs.value.node) = new ComparisonNode('L', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 905 "parser.cpp"
    break;

  case 45: // expression: expression PLUS expression
#line 259 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('+', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 913 "parser.cpp"
    break;

  case 46: // expression: expression MINUS expression
#line 263 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('-', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 921 "parser.cpp"
    break;

  case 47: // expression: expression MULTIPLY expression
#line 267 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('*', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 929 "parser.cpp"
    break;

  case 48: // expression: expression DIVIDE expression
#line 271 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('/', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 937 "parser.cpp"
    break;

  case 49: // expression: expression MODULO expression
#line 275 "parser.y"
        {
            (yylhs.value.node) = new ArithmeticOpNode('%', (yystack_[2].value.node), (yystack_[0].value.node));
        }
#line 945 "parser.cpp"
    break;

  case 50: // expression: LPAREN expression RPAREN
#line 279 "parser.y"
        {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 953 "parser.cpp"
    break;

  case 51: // expression: UNSIGNED_INT
#line 283 "parser.y"
        {
            (yylhs.value.node) = new IntNode((yystack_[0].value.int_val));
        }
#line 961 "parser.cpp"
    break;

  case 52: // expression: BOOL_CONST
#line 287 "parser.y"
        {
            (yylhs.value.node) = new BoolNode((yystack_[0].value.bool_val));
        }
#line 969 "parser.cpp"
    break;

  case 53: // expression: IDENTIFIER
#line 291 "parser.y"
        {
            (yylhs.value.node) = new VariableNode(std::string((yystack_[0].value.id)));
        }
#line 977 "parser.cpp"
    break;

  case 54: // expression: array_access
#line 295 "parser.y"
        {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 985 "parser.cpp"
    break;

  case 55: // array_access: IDENTIFIER LPAREN expressions RPAREN
#line 302 "parser.y"
        {
            (yylhs.value.node) = new ArrayAccessNode(std::string((yystack_[3].value.id)), (yystack_[1].value.expr_list));
        }
#line 993 "parser.cpp"
    break;

  case 56: // expressions: expression
#line 309 "parser.y"
        {
            (yylhs.value.expr_list) = new std::vector<ASTNode*>();
            (yylhs.value.expr_list)->push_back((yystack_[0].value.node));
        }
#line 1002 "parser.cpp"
    break;

  case 57: // expressions: expressions COMMA expression
#line 314 "parser.y"
        {
            (yystack_[2].value.expr_list)->push_back((yystack_[0].value.node));
            (yylhs.value.expr_list) = (yystack_[2].value.expr_list);
        }
#line 1011 "parser.cpp"
    break;

  case 58: // expressions: %empty
#line 319 "parser.y"
        { (yylhs.value.expr_list) = new std::vector<ASTNode*>(); }
#line 1017 "parser.cpp"
    break;

  case 59: // return_variables: LBRACKET variables RBRACKET
#line 324 "parser.y"
        { (yylhs.value.var_list) = (yystack_[1].value.var_list); }
#line 1023 "parser.cpp"
    break;

  case 60: // return_variables: variables
#line 326 "parser.y"
        { (yylhs.value.var_list) = (yystack_[0].value.var_list); }
#line 1029 "parser.cpp"
    break;

  case 61: // parameters: variables
#line 331 "parser.y"
        { (yylhs.value.var_list) = (yystack_[0].value.var_list); }
#line 1035 "parser.cpp"
    break;

  case 62: // parameters: %empty
#line 333 "parser.y"
        { (yylhs.value.var_list) = new std::vector<VariableNode*>(); }
#line 1041 "parser.cpp"
    break;

  case 63: // variables: IDENTIFIER
#line 338 "parser.y"
        {
            (yylhs.value.var_list) = new std::vector<VariableNode*>();
            (yylhs.value.var_list)->push_back(new VariableNode(std::string((yystack_[0].value.id))));
        }
#line 1050 "parser.cpp"
    break;

  case 64: // variables: variables COMMA IDENTIFIER
#line 343 "parser.y"
        {
            (yystack_[2].value.var_list)->push_back(new VariableNode(std::string((yystack_[0].value.id))));
            (yylhs.value.var_list) = (yystack_[2].value.var_list);
        }
#line 1059 "parser.cpp"
    break;

  case 65: // movement_operator: FORW
#line 351 "parser.y"
        { (yylhs.value.node) = new MovementNode("FORW"); }
#line 1065 "parser.cpp"
    break;

  case 66: // movement_operator: BACK
#line 353 "parser.y"
        { (yylhs.value.node) = new MovementNode("BACK"); }
#line 1071 "parser.cpp"
    break;

  case 67: // movement_operator: RIGHT_OP
#line 355 "parser.y"
        { (yylhs.value.node) = new MovementNode("RIGHT"); }
#line 1077 "parser.cpp"
    break;

  case 68: // movement_operator: LEFT_OP
#line 357 "parser.y"
        { (yylhs.value.node) = new MovementNode("LEFT"); }
#line 1083 "parser.cpp"
    break;

  case 69: // sensor_operator: GETF
#line 362 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETF"); }
#line 1089 "parser.cpp"
    break;

  case 70: // sensor_operator: GETB
#line 364 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETB"); }
#line 1095 "parser.cpp"
    break;

  case 71: // sensor_operator: GETR
#line 366 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETR"); }
#line 1101 "parser.cpp"
    break;

  case 72: // sensor_operator: GETL
#line 368 "parser.y"
        { (yylhs.value.node) = new SensorNode("GETL"); }
#line 1107 "parser.cpp"
    break;

  case 73: // sensor_operator: PUSHF
#line 370 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHF"); }
#line 1113 "parser.cpp"
    break;

  case 74: // sensor_operator: PUSHB
#line 372 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHB"); }
#line 1119 "parser.cpp"
    break;

  case 75: // sensor_operator: PUSHR
#line 374 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHR"); }
#line 1125 "parser.cpp"
    break;

  case 76: // sensor_operator: PUSHL
#line 376 "parser.y"
        { (yylhs.value.node) = new SensorNode("PUSHL"); }
#line 1131 "parser.cpp"
    break;

  case 77: // sensor_operator: UNDO
#line 378 "parser.y"
        { (yylhs.value.node) = new SensorNode("UNDO"); }
#line 1137 "parser.cpp"
    break;


#line 1141 "parser.cpp"

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









  const signed char Parser::yypact_ninf_ = -123;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
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
  Parser::yydefact_[] =
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
  Parser::yypgoto_[] =
  {
    -123,  -123,   145,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -122,  -123,   -51,     1,  -102,
    -123,  -123,    -4,  -123,  -123
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    56,    83,    82,    84,
      48,   156,    49,    50,    51
  };

  const unsigned char
  Parser::yytable_[] =
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
  Parser::yycheck_[] =
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
  Parser::yystos_[] =
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
  Parser::yyr1_[] =
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
  Parser::yyr2_[] =
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
  Parser::yyrline_[] =
  {
       0,    79,    79,    82,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   106,   110,   117,
     124,   128,   135,   139,   146,   150,   154,   158,   165,   169,
     176,   183,   190,   197,   201,   208,   215,   217,   222,   231,
     234,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282,   286,   290,   294,   301,   308,   313,   319,   323,
     325,   330,   333,   337,   342,   350,   352,   354,   356,   361,
     363,   365,   367,   369,   371,   373,   375,   377
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

#line 21 "parser.y"
} // Parser
#line 1645 "parser.cpp"

#line 381 "parser.y"


void yyerror(Parser::context_type& context, const char *s) {
    std::cerr << "Error at " << context.location.begin.filename << ":"
              << context.location.begin.line << ":"
              << context.location.begin.column << " - " << s << std::endl;
    exit(1);
}
