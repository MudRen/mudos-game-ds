// �H�ѴѽL Big5 ���� v1.0
// ��@:  �Z�L�~�v��EDD
// �ק�:  luky @ ds.muds.net
//

#include <ansi.h>
#define che TABLE[table[sROW]][sCOL][2]
#define cc TABLE[table[sROW]][sCOL][3]
#define cc1 TABLE[table[tROW]][tCOL][3]
inherit ITEM;
inherit F_SAVE;

string bche = "";
string rche = "";
string aaa = "";
int aa = 0;
int bb = 0;


mapping TABLE = ([ // table /*�z�{�|�}�w�x�u�t�s�r�q*/
0: ([
        0 :({ "�z",HIR"��"NOR, 1,1 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�s",HIR"��"NOR, 2,1 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�s",HIR"��"NOR, 3,1 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�s",HIR"�K"NOR, 4,1 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�s",HIR"��"NOR, 5,1 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�s",HIR"�K"NOR, 4,1 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�s",HIR"��"NOR, 3,1 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�s",HIR"��"NOR, 2,1 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�{",HIR"��"NOR, 1,1 }),
        ]),
1: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "�@", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "��", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),

2: ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 }),
        ]),
3: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "��", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "�@", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
4 : ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q",HIR"��"NOR, 6,1 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q",HIR"��"NOR, 6,1 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 }),
        ]),
5 : ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
6 : ([
        0 :({ "�u",HIR"�L"NOR, 7,1 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q",HIR"�L"NOR, 7,1 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q",HIR"�L"NOR, 7,1 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q",HIR"�L"NOR, 7,1 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
	15:({ "�w", "  ", 0,0 }),
        16:({ "�t",HIR"�L"NOR, 7,1 }),
        ]),
7 : ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
8 : ([
	0 :({ "�|", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�r", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�r", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�r", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�r", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�r", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�r", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�r", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�}", "  ", 0,0 }),
        ]),
9 : ([
        0 : ({ " ��� ��  �e ����� �~  �� ��� ", "  ", 0,0 }),
        ]),
10: ([
        0 :({ "�z", "  ", 0,0 }),
	1 :({ "�w", "  ", 0,0 }),
        2 :({ "�s", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�s", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�s", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�s", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�s", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�s", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�s", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�{", "  ", 0,0 }),
        ]),
11: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
12 : ([
        0 :({ "�u",HIC"��"NOR, 7,2 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q",HIC"��"NOR, 7,2 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q",HIC"��"NOR, 7,2 }),
	9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q",HIC"��"NOR, 7,2 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t",HIC"��"NOR, 7,2 }),
        ]),
13: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
14: ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q",HIC"�]"NOR, 6,2 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q",HIC"�]"NOR, 6,2 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 })
	]),
15: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "�@", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "��", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
16: ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 })
        ]),
18: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "��", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "�@", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
19: ([
        0 :({ "�|",HIC"��"NOR, 1,2 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�r",HIC"��"NOR, 2,2 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�r",HIC"�H"NOR, 3,2 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�r",HIC"�h"NOR, 4,2 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�r",HIC"�N"NOR, 5,2 }),
        9 :({ "�w", "  ", 0,0 }),
	10:({ "�r",HIC"�h"NOR, 4,2 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�r",HIC"�H"NOR, 3,2 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�r",HIC"��"NOR, 2,2 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�}",HIC"��"NOR, 1,2 }),
        ]),

]);

string *table;

string *tossText = ({

        "�x      �x\n"
        "�x  "HIR"��"NOR"  �x\n"
        "�x      �x\n",

        "�x  ��  �x\n"
        "�x      �x\n"
        "�x  ��  �x\n",

"�x��    �x\n"
        "�x  ��  �x\n"
        "�x    ���x\n",

        "�x"HIR"��  ��"NOR"�x\n"
        "�x      �x\n"
        "�x"HIR"��  ��"NOR"�x\n",

        "�x��  ���x\n"
        "�x  ��  �x\n"
        "�x��  ���x\n",

        "�x��  ���x\n"
        "�x��  ���x\n"
        "�x��  ���x\n",

        "�z�w�w�w�{\n",
        "�|�w�w�w�}\n",
});


int init_tab();
int do_display(string arg);
int do_move(string arg);
int do_toss();
string long();
string query_save_file();
void do_check();
int do_save();
int do_deploy();

string *query_table(){ return table; }

void create()
{
        set_name("����H�ѽL", ({ "chinese chess board","ccb","board" }) );
        set_weight(500000);
        set_max_encumbrance(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long", "�o�O�@�i����H�ѽL�A�ΨӤU�H�Ѫ��C\n");
                set("value", 0);
                set("material", "wood");
                set("no_get",1);
                set("no_sac",1);
                set("no_drop",1);
        }
        setup();
        init_tab();
}
void init()
{
        add_action("do_move","move");   
        add_action("do_toss","toss");
        add_action("do_reset","reset");
        add_action("do_save","csave");
        add_action("do_deploy","deploy");
        add_action("do_lose","lose");
        add_action("do_help","help");
        add_action("do_review","review");
        add_action("do_view",".");
}

string query_save_file()
{ 
	if( bb == 1 )
	return DATA_DIR + "cchess/" + this_player()->query("id")[0..0] + "/" + this_player()->query("id"); 
	else return DATA_DIR + "cchess/cchess"; 
}

int init_tab()
{

TABLE = ([ // table /*�z�{�|�}�w�x�u�t�s�r�q*/
0: ([
        0 :({ "�z",HIR"��"NOR, 1,1 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�s",HIR"��"NOR, 2,1 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�s",HIR"��"NOR, 3,1 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�s",HIR"�K"NOR, 4,1 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�s",HIR"��"NOR, 5,1 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�s",HIR"�K"NOR, 4,1 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�s",HIR"��"NOR, 3,1 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�s",HIR"��"NOR, 2,1 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�{",HIR"��"NOR, 1,1 }),
        ]),
1: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "�@", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "��", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),

2: ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 }),
        ]),
3: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "��", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "�@", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
4 : ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q",HIR"��"NOR, 6,1 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q",HIR"��"NOR, 6,1 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 }),
        ]),
5 : ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
6 : ([
        0 :({ "�u",HIR"�L"NOR, 7,1 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q",HIR"�L"NOR, 7,1 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q",HIR"�L"NOR, 7,1 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q",HIR"�L"NOR, 7,1 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
	15:({ "�w", "  ", 0,0 }),
        16:({ "�t",HIR"�L"NOR, 7,1 }),
        ]),
7 : ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
8 : ([
	0 :({ "�|", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�r", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�r", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�r", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�r", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�r", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�r", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�r", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�}", "  ", 0,0 }),
        ]),
9 : ([
        0 : ({ " ��� ��  �e ����� �~  �� ��� ", "  ", 0,0 }),
        ]),
10: ([
        0 :({ "�z", "  ", 0,0 }),
	1 :({ "�w", "  ", 0,0 }),
        2 :({ "�s", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�s", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�s", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�s", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�s", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�s", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�s", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�{", "  ", 0,0 }),
        ]),
11: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
12 : ([
        0 :({ "�u",HIC"��"NOR, 7,2 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q",HIC"��"NOR, 7,2 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q",HIC"��"NOR, 7,2 }),
	9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q",HIC"��"NOR, 7,2 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t",HIC"��"NOR, 7,2 }),
        ]),
13: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "  ", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "  ", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
14: ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q",HIC"�]"NOR, 6,2 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q",HIC"�]"NOR, 6,2 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 })
	]),
15: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
        6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "�@", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "��", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
16: ([
        0 :({ "�u", "  ", 0,0 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�q", "  ", 0,0 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�q", "  ", 0,0 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�q", "  ", 0,0 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�q", "  ", 0,0 }),
        9 :({ "�w", "  ", 0,0 }),
        10:({ "�q", "  ", 0,0 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�q", "  ", 0,0 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�q", "  ", 0,0 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�t", "  ", 0,0 })
        ]),
18: ([
        0 : ({ "�x", "  ", 0,0 }),
        1 : ({ "  ", "  ", 0,0 }),
        2 : ({ "�x", "  ", 0,0 }),
        3 : ({ "  ", "  ", 0,0 }),
        4 : ({ "�x", "  ", 0,0 }),
        5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "�x", "  ", 0,0 }),
        7 : ({ "��", "  ", 0,0 }),
        8 : ({ "�x", "  ", 0,0 }),
        9 : ({ "�@", "  ", 0,0 }),
        10: ({ "�x", "  ", 0,0 }),
        11: ({ "  ", "  ", 0,0 }),
        12: ({ "�x", "  ", 0,0 }),
        13: ({ "  ", "  ", 0,0 }),
        14: ({ "�x", "  ", 0,0 }),
        15: ({ "  ", "  ", 0,0 }),
        16: ({ "�x", "  ", 0,0 })
        ]),
19: ([
        0 :({ "�|",HIC"��"NOR, 1,2 }),
        1 :({ "�w", "  ", 0,0 }),
        2 :({ "�r",HIC"��"NOR, 2,2 }),
        3 :({ "�w", "  ", 0,0 }),
        4 :({ "�r",HIC"�H"NOR, 3,2 }),
        5 :({ "�w", "  ", 0,0 }),
        6 :({ "�r",HIC"�h"NOR, 4,2 }),
        7 :({ "�w", "  ", 0,0 }),
        8 :({ "�r",HIC"�N"NOR, 5,2 }),
        9 :({ "�w", "  ", 0,0 }),
	10:({ "�r",HIC"�h"NOR, 4,2 }),
        11:({ "�w", "  ", 0,0 }),
        12:({ "�r",HIC"�H"NOR, 3,2 }),
        13:({ "�w", "  ", 0,0 }),
        14:({ "�r",HIC"��"NOR, 2,2 }),
        15:({ "�w", "  ", 0,0 }),
        16:({ "�}",HIC"��"NOR, 1,2 }),
        ]),

]);
        table = keys(TABLE);
        table = sort_array(table,1);
        
		bche = "";
		rche = "";
		aaa = "";
		aa = 0;
		bb = 0;
		delete("id1");
		delete("id2");
		delete("over");
		delete("name1");
		delete("name2");
		delete("num");
		delete("first");
		delete("round");
		
        return 1;
}

int do_move(string arg)
{
        int sROW,sCOL,tROW,tCOL,i,ii,x,y,tem,tem1,tem2,tem3,tem4;
        string msg,msg1;
	object ob,me; 
	ob = this_object();
	me = this_player();
	msg1 = "";

	if( ob->query("over") ) return notify_fail("�o�L�Ѥw�g�����F�C \n");

	if( me->name() != ob->query("name1") && me->name() != ob->query("name2") )
		return notify_fail("�A�٬O�����l�a�I\n");

	if( !ob->query("name2") ) return notify_fail("�٭n���@�ӤH�~��U�ѡI\n");

	if( ob->query("round") == 0 && ob->query("first") != me->name() ) return notify_fail("�o�Ӧ^�X���ӧA���ѡI\n");

	if( ob->query("round") == 1 && ob->query("first") == me->name() ) return notify_fail("�o�Ӧ^�X���ӧA���ѡI\n");

        if( !arg ) return notify_fail("���ʴѤl�Gmove ��� �a���� to ��� �a���� \n");

        if( sscanf(arg,"%d %d to %d %d",sCOL,sROW,tCOL,tROW) != 4 )
                return notify_fail("���ʴѤl�Gmove ��� �a���� to ��� �a���� \n");

	if( tCOL > 9 || tCOL < 1 || tROW > 9 || tROW < 0 || sCOL > 9 || sCOL < 1 || sROW > 9 || sROW < 0)
                return notify_fail("�A����J�w�g�W�V�H�ѽL�ɽu�F�C\n");

	if( tCOL == sCOL && sROW == tROW ) return notify_fail("�o�٥β��ʶܡH\n");

        sCOL -= 1;
        tCOL -= 1;

        sROW = sROW * 2;
        tROW = tROW * 2;
        sCOL = sCOL * 2;
        tCOL = tCOL * 2;

        if( TABLE[table[sROW]][sCOL][1] == "  " ) return notify_fail("�o�Ӧa��S���Ѥl�C\n");

	if( TABLE[table[tROW]][tCOL][3] == TABLE[table[sROW]][sCOL][3] ) return notify_fail("�A�n�Y���ۤv���Ѥl�H\n");

	if( ob->query("round") == 0 && cc != 1 ) return notify_fail("�A�����Ѥl�F�a�I\n");

	if( ob->query("round") == 1 && cc != 2 ) return notify_fail("�A�����Ѥl�F�a�I\n");


	//�� 
	if( che == 1 )
	{
		if( tCOL != sCOL && sROW != tROW ) return notify_fail("�o�ӴѤl�u�ਫ���u�C\n");
	
		if( tCOL > sCOL && tCOL - sCOL > 2 )
			for (i=sCOL+2;i<tCOL;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[sROW]][i][1] != "  " )
					return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
	
		if( sCOL > tCOL && sCOL - tCOL > 2 )
			for (i=tCOL+2;i<sCOL;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[sROW]][i][1] != "  " )
					return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
	
		if( tROW > sROW && tROW - sROW > 2  )
			for (i=sROW+2;i<tROW;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[i]][sCOL][1] != "  " )
					return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
	
		if( sROW > tROW && sROW - tROW > 2 )
			for (i=tROW+2;i<sROW;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[i]][sCOL][1] != "  " )
					return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
	}

	//��
	if( che == 2 )
	{
		if( tCOL == sCOL || sROW == tROW )
			return notify_fail("�����ਫ���u�C\n");
	
		if( tCOL < (sCOL - 4) || tCOL > (sCOL + 4) || tROW < (sROW - 4) || tROW > (sROW + 4 ) )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( (tCOL == sCOL - 2 || tCOL == sCOL + 2) && (tROW != sROW - 4 && tROW != sROW + 4) )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( (tCOL == sCOL - 4 || tCOL == sCOL + 4) && (tROW != sROW - 2 && tROW != sROW + 2) )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( sCOL-tCOL < -2 && TABLE[table[sROW]][sCOL+2][1] != "  " )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( sCOL-tCOL > 2 && TABLE[table[sROW]][sCOL-2][1] != "  " )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( sROW-tROW > 2 && TABLE[table[sROW-2]][sCOL][1] != "  "  )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( sROW-tROW < -2 && TABLE[table[sROW+2]][sCOL][1] != "  " )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	}
	//��
	if( che == 3 )
	{
		if( tCOL == sCOL || sROW == tROW )
			return notify_fail("�ۤ��ਫ���u�C\n");
	
		if( (tROW != sROW-4 && tROW != sROW+4) || (tCOL != sCOL-4 && tCOL != sCOL+4) )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( tCOL > sCOL )
		{
			if( tROW > sROW && TABLE[table[sROW+2]][sCOL+2][1] != "  " )
				return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
			if( tROW < sROW && TABLE[table[sROW-2]][sCOL+2][1] != "  " )
				return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
	
		if( tCOL < sCOL )
		{
			if( tROW > sROW && TABLE[table[sROW+2]][sCOL-2][1] != "  " )
				return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
			if( tROW < sROW && TABLE[table[sROW-2]][sCOL-2][1] != "  " )
				return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
	
		if( (cc == 1 && tROW > 9) || (cc == 2 && tROW < 9) )
			return notify_fail("�ۤ���L�e�C\n");
	}
	
	//�K
	if( che == 4 )
	{
	
		if( tCOL == sCOL || sROW == tROW ) return notify_fail("�K���ਫ���u�C\n");
	
		if( (tROW != sROW-2 && tROW != sROW+2) || (tCOL != sCOL-2 && tCOL != sCOL+2) )
			return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( cc == 1 && (tCOL > 10 || tCOL < 6 || tROW > 4) )
			return notify_fail("���Ӧ�m�W�X�K���ʪ��S��F�C\n");
	
		if( cc == 2 && (tCOL > 10 || tCOL < 6 || tROW < 14) )
			return notify_fail("���Ӧ�m�W�X�K���ʪ��S��F�C\n");
	}
	
	//��
	if( che == 5 )
	{
		if( tCOL != sCOL && sROW != tROW )
			return notify_fail("�o�ӴѤl�u�ਫ���u�C\n");
	
		if( tCOL - sCOL > 2 || tCOL - sCOL < -2 || tROW - sROW > 2 || tROW - sROW < -2 )
			return notify_fail("�Ӥ@���u�ਫ�@��C\n");
	
		if( cc == 1 )
			if( tCOL > 10 || tCOL < 6 || tROW > 4 )
				return notify_fail("���Ӧ�m�W�X�Ӳ��ʪ��S��F�C\n");
	
		if( cc == 2 )
			if( tCOL > 10 || tCOL < 6 || tROW < 14 )
				return notify_fail("���Ӧ�m�W�X�Ӳ��ʪ��S��F�C\n");
	}

	//��
	if( che == 6 )
	{
		ii = 0;
	
		if( tCOL != sCOL && sROW != tROW ) return notify_fail("�o�ӴѤl�u�ਫ���u�C\n");
	
		if( cc1 != 0 )
			if( tCOL - sCOL == 2 || tCOL - sCOL == -2 || tROW - sROW == 2 || tROW - sROW == -2 )
				return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
	
		if( tCOL > sCOL )
		{
			for (i=sCOL+2;i<tCOL;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[sROW]][i][1] != "  " )	ii += 1;
				if( ii > 1 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
				if( ii == 1 && cc1 == 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
			if( ii == 0 && cc1 != 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}

		if( sCOL > tCOL )
		{
			for (i=tCOL+2;i<sCOL;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[sROW]][i][1] != "  " )	ii += 1;
				if( ii > 1 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
				if( ii == 1 && cc1 == 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
			if( ii == 0 && cc1 != 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
		
		if( tROW > sROW && tROW - sROW > 2  )
		{
			for (i=sROW+2;i<tROW;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[i]][sCOL][1] != "  " ) ii += 1;
				if( ii > 1 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
				if( ii == 1 && cc1 == 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
			if( ii == 0 && cc1 != 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
		
		if( sROW > tROW && sROW - tROW > 2 )
		{
			for (i=tROW+2;i<sROW;i++)
			{
				if( i%2!=0) continue;
				if( TABLE[table[i]][sCOL][1] != "  " )	ii += 1;
				if( ii > 1 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
				if( ii == 1 && cc1 == 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
			}
			if( ii == 0 && cc1 != 0 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
	}

	//�L
	if( che == 7 )
	{
		if( tCOL - sCOL > 2 || tCOL - sCOL < -2 || tROW - sROW > 2 || tROW - sROW < -2 )
			return notify_fail("�L�@���u�ਫ�@��C\n");
		if( tCOL != sCOL && sROW != tROW ) return notify_fail("�o�ӴѤl�u�ਫ���u�C\n");
		if( cc == 1 )
		{
			if( sROW > tROW ) return notify_fail("�L���੹�^���C\n");
			if( tCOL != sCOL && sROW < 9 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
		
		if( cc == 2 )
		{
			if( sROW < tROW ) return notify_fail("�L���੹�^���C\n");
			if( tCOL != sCOL && sROW > 9 ) return notify_fail("�o�ӴѤl���ಾ�ʨ쨺�Ӧa��C\n");
		}
	}

	if ( TABLE[table[tROW]][tCOL][2] != 0 )
	{
		msg1 += "$N�Y���F���@��" + sprintf("%s�C\n",TABLE[table[tROW]][tCOL][1]);
		if( cc1 == 1 ) bche+=TABLE[table[tROW]][tCOL][1];
		else rche+=TABLE[table[tROW]][tCOL][1];
	}

	if ( TABLE[table[tROW]][tCOL][2] == 5 )
	{
		msg1 += HIY"$NĹ�o�F�o�����ɪ��ӧQ�C\n"NOR;
		ob->set("over",this_player()->name());
	}

        TABLE[table[tROW]][tCOL][1] = TABLE[table[sROW]][sCOL][1];
	TABLE[table[tROW]][tCOL][2] = TABLE[table[sROW]][sCOL][2];
	TABLE[table[tROW]][tCOL][3] = TABLE[table[sROW]][sCOL][3];
        TABLE[table[sROW]][sCOL][1] = "  ";
	TABLE[table[sROW]][sCOL][2] = 0; 
	TABLE[table[sROW]][sCOL][3] = 0; 

	tem4 = 0;
        for( y=0;y<6;y++ )
        {
		if( y%2 != 0 ) continue;
                for( x=6;x<12;x++ )
                {
			if( x%2 != 0 ) continue;
                        if( TABLE[table[y]][x][2] == 5 )
                        {
				tem = x;
				tem3 = y;
				break;
                	}
		}
	}

        for( y=14;y<19;y++ )
        {
		if( y%2 != 0 ) continue;
                for( x=6;x<12;x++ )
                {
			if( x%2 != 0 ) continue;
                        if( TABLE[table[y]][x][2] == 5 )
                        {
				tem1 = x;
				tem2 = y;
				break;
			}
                }
	}

	if( tem == tem1 )
	{
		for (i=tem3+2;i<tem2;i++)
		{
			if( i%2!=0) continue;
			if( TABLE[table[i]][tem][1] != "  " ) tem4 = 1; 
		}
		if( tem4 == 0 )
		{
        		msg1 += (sprintf(HIY"%sĹ�o�F�o�����ɪ��ӧQ�C\n"NOR,
			ob->query("name1") == me->name()?ob->query("name2"):
			ob->query("name1")) ); 
			ob->set("over", ob->query("name1") == me->name()?ob->query("name2"):
			ob->query("name1") );
		}
	}

        if( sROW == tROW )
		if( cc1 == 2 ) msg = sprintf("�y%s�z%s��%s",
                                        TABLE[table[tROW]][tCOL][1],
                                        chinese_number(sCOL/2+1),
                                        chinese_number(tCOL/2+1) );
		else msg = sprintf("�y%s�z%s��%s",
                                        TABLE[table[tROW]][tCOL][1],
                                        chinese_number(10-(sCOL/2+1)),
                                        chinese_number(10-(tCOL/2+1)) );

        else
        	if( cc1 == 2 )
                	if( sROW>tROW )  msg = sprintf("�y%s�z%s�i%s",
					TABLE[table[tROW]][tCOL][1],
                                        chinese_number(sCOL/2+1),
                                        sCOL==tCOL?chinese_number( (sROW-tROW)/2 ):chinese_number(tCOL/2+1) );
                	else msg = sprintf("�y%s�z%s�h%s",
                                        TABLE[table[tROW]][tCOL][1],
                                        chinese_number(sCOL/2+1),
                                        sCOL==tCOL?chinese_number( (tROW-sROW)/2 ):chinese_number(tCOL/2+1) );

		else 
	 		if( tROW>sROW ) msg = sprintf("�y%s�z%s�i%s",
					TABLE[table[tROW]][tCOL][1],
					chinese_number(10-(sCOL/2+1)),
                                        sCOL==tCOL?chinese_number( (tROW-sROW)/2 ):chinese_number(10-(tCOL/2+1)) );
                	else msg = sprintf("�y%s�z%s�h%s",
                                        TABLE[table[tROW]][tCOL][1],
					chinese_number(10-(sCOL/2+1)),
                                        sCOL==tCOL?chinese_number( (sROW-tROW)/2 ):chinese_number(10-(tCOL/2+1)) );

        message_vision( "$N�U�F�@��"+msg+"\n",this_player());
        message_vision( msg1,me);
	do_check();

	if( aa == 4 )
	{
		aaa += msg+"\n"; 
		aa = 0;
	}
	else 
	{
			aaa += msg+" ";
			aa += 1;
	}

	ob->query("round") == 1?ob->set("round",0):ob->set("round",1);
	return 1;
}

int do_toss()
{
        int num;
        string text;
	object me, ob;
	me = this_player();
	ob = this_object();

	if( ob->query("name2") ) return notify_fail("�w�g����ӤH�b�U�ѤF�C\n");
	
	if( me->name() == ob->query("name1") ) return notify_fail("�A�w�g��L�@����l�F�C\n");
	
	num = random(6);
	
	if( ob->query("num") == num )  num = random(6);
	
	text = "���_��l�b�⤤�n�F��n, �Y�X�F�@�ӡG\n";
	text += tossText[6]+tossText[num]+tossText[7];
	message_vision( "$N"+text,me );
	
	if( ob->query("name1") )
	{
		ob->query("num")>num ? ob->set("first",ob->query("name1")) : ob->set("first",me->name());
	        message_vision( ob->query("first")+"�ϥά���Ѥl����C\n",me );
	}
	
	ob->set("num",num);
	ob->query("name1")?ob->set("name2",me->name()): ob->set("name1",me->name());
	ob->query("id1")?ob->set("id2",me->query("id")):ob->set("id1",me->query("id"));
	return 1;
}

string long()
{
        int row,col,i;
        string text,round,msg;
	object ob,me;
	ob = this_object();
	me = this_player();

        text = "\n1   2   3   4   5   6   7   8   9\n";

	msg = ob->query("name1")==ob->query("first") ? ob->query("name2") : ob->query("name1");

	if( ob->query("name2") )
	{
		if( ob->query("over") )	round = "   �o�L��"+ob->query("over")+"Ĺ�F�C";
		else if( ob->query("round") == 1 ) round = "   �{�b����"+HIC"�Ťl"NOR+"�U";
		else round = "   �{�b����"+HIR"���l"NOR+"�U";
		TABLE[table[9]][0][1] = sprintf("%s%s",TABLE[table[9]][0][0],round );
	}
	
	if( me->name() != ob->query("first") )
	{
		TABLE[table[17]][0][1] = "�x";
		TABLE[table[3]][0][1] = "�x";
		TABLE[table[5]][0][1] = "�x";
		TABLE[table[13]][0][1] = "�x";
		TABLE[table[15]][0][1] = "�x";
		TABLE[table[0]][0][0] = "�z";
		TABLE[table[10]][0][0] = "�z";
		TABLE[table[0]][16][0] = "�{";
		TABLE[table[10]][16][0] = "�{";
		TABLE[table[18]][16][0] = "�}";
		TABLE[table[8]][16][0] = "�}";
		TABLE[table[8]][0][0] = "�|";
		TABLE[table[18]][0][0] = "�|";
		TABLE[table[2]][16][0] = TABLE[table[4]][16][0]
		= TABLE[table[6]][16][0] = TABLE[table[12]][16][0]
		= TABLE[table[14]][16][0] = TABLE[table[16]][16][0]
		= "�t";
		TABLE[table[2]][0][0] = TABLE[table[4]][0][0]
		= TABLE[table[6]][0][0] = TABLE[table[12]][0][0]
		= TABLE[table[14]][0][0] = TABLE[table[16]][0][0]
		= "�u";
	
		TABLE[table[1]][16][1] = "�x   �p�����D�A�аѬݡ�help cchess��";
		TABLE[table[15]][16][1] = sprintf("%s%s%s",TABLE[table[15]][16][0]," ","  "+bche );
		TABLE[table[5]][16][1] = sprintf("%s%s%s",TABLE[table[5]][16][0]," ","  "+rche );
	
		if( ob->query("name2") )
		{
			TABLE[table[3]][16][1] = sprintf("%s%s%s","�x","   ("+ob->query("first")+") ",HIR"����"NOR+"�ҦY�Ѥl�G" );
			TABLE[table[13]][16][1] = sprintf("%s%s%s","�x","   ("+msg+") ",HIC"�Ť�"NOR+"�ҦY�Ѥl�G" );
		}
	
		for( i=2;i<16;i++)
		{
			if( i%2!=0) continue;
			TABLE[table[8]][i][0] = "�r";
			TABLE[table[10]][i][0] = "�s";
			TABLE[table[18]][i][0] = "�r";
			TABLE[table[0]][i][0] = "�s";
		}
	
	        for( row=0; row<sizeof(table); row++ )
	        {
	                for( col=0; col<sizeof(TABLE[table[row]]); col++ )
	                {
	                        if( TABLE[table[row]][col][1] == "  " )
	                                text += sprintf("%s", TABLE[table[row]][col][0] );
	                        else
	                                text += sprintf("%s", TABLE[table[row]][col][1] );
	                }
	                if( row%2 == 0)
	                        text += sprintf(" %d", row/2 );
	                text += "\n";
	        }
	} 
	else
	{
	        text = "\n9   8   7   6   5   4   3   2   1\n";
		TABLE[table[1]][16][1] = "�x";
		TABLE[table[3]][16][1] = "�x";
		TABLE[table[5]][16][1] = "�x";
		TABLE[table[13]][16][1] = "�x";
		TABLE[table[15]][16][1] = "�x";
		TABLE[table[0]][0][0] = "�}";
		TABLE[table[18]][16][0]= "�z";
		TABLE[table[0]][16][0] = "�|";
		TABLE[table[18]][0][0] = "�{";
		TABLE[table[8]][16][0] = "�z";
		TABLE[table[10]][16][0] = "�|";
		TABLE[table[2]][16][0] = TABLE[table[4]][16][0]
		= TABLE[table[6]][16][0] = TABLE[table[12]][16][0]
		= TABLE[table[14]][16][0] = TABLE[table[16]][16][0]
		= "�u";
		TABLE[table[10]][0][0] = "�}";
		TABLE[table[8]][0][0] = "�{";
		TABLE[table[2]][0][0] = TABLE[table[4]][0][0]
		= TABLE[table[6]][0][0] = TABLE[table[12]][0][0]
		= TABLE[table[14]][0][0] = TABLE[table[16]][0][0]
		= "�t";
	
		TABLE[table[17]][0][1] = "�x   �p�����D�A�аѬݡ�help cchess��";
		TABLE[table[13]][0][1] = sprintf("%s%s%s",TABLE[table[15]][16][0]," ","  "+bche );
		TABLE[table[3]][0][1] = sprintf("%s%s%s",TABLE[table[5]][16][0]," ","  "+rche );
	
		if( ob->query("name2") )
		{
			TABLE[table[5]][0][1] = sprintf("%s%s%s","�x","   ("+ob->query("first")+") ",HIR"����"NOR+"�ҦY�Ѥl�G" );
			TABLE[table[15]][0][1] = sprintf("%s%s%s","�x","   ("+msg+") ",HIC"�Ť�"NOR+"�ҦY�Ѥl�G" );
		}
	
		for( i=2;i<16;i++)
		{
			if( i%2!=0) continue;
			TABLE[table[8]][i][0] = "�s";
			TABLE[table[10]][i][0] = "�r";
			TABLE[table[18]][i][0] = "�s";
			TABLE[table[0]][i][0] = "�r";
		}
	
	        for( row=(sizeof(table)-1); row>-1; row-- )
	        {
	                for( col=(sizeof(TABLE[table[row]])-1); col>-1; col-- )
	                {
	                        if( TABLE[table[row]][col][1] == "  " )
	                                text += sprintf("%s", TABLE[table[row]][col][0] );
	                        else
	                                text += sprintf("%s", TABLE[table[row]][col][1] );
	                }
	                if( row%2 == 0)
	                        text += sprintf(" %d", row/2 );
	                text += "\n";
	        }
	}
	return text;
}

void do_check()
{
	int x,y,tem,tem1,i,tem3,check;
	object ob = this_object();
	check = 0;

	if( ob->query("over") ) return;

	if( ob->query("round") == 1 )
        for( y=0;y<5;y++ )
        {
		if( y%2 != 0 ) continue;
                for( x=6;x<11;x++ )
                {
			if( x%2 != 0 ) continue;
                        if( TABLE[table[y]][x][2] == 5 )
                        {
				tem = x;
				tem1 = y;
				break;
                	}
		}
	}
	else
        for( y=14;y<19;y++ )
        {
		if( y%2 != 0 ) continue;
                for( x=6;x<11;x++ )
                {
			if( x%2 != 0 ) continue;
                        if( TABLE[table[y]][x][2] == 5 )
                        {
				tem = x;
				tem1 = y;
				break;
			}
                }
	}

	if( tem1 < 9 )
	if( TABLE[table[tem1+2]][tem][2] == 7 && TABLE[table[tem1+2]][tem][3] != TABLE[table[tem1]][tem][3] )
		check = 1;

	if( tem1 > 9 )
	if( TABLE[table[tem1-2]][tem][2] == 7 && TABLE[table[tem1-2]][tem][3] != TABLE[table[tem1]][tem][3] )
		check = 1;

	if( TABLE[table[tem1]][tem+2][2] == 7 ) check = 1;

	if( TABLE[table[tem1]][tem-2][2] == 7 )	check = 1;


	tem3 = 0;
	for (i=tem+2;i<17;i++)
	{
		if( i%2!=0) continue;
		if( tem3 == 1 && TABLE[table[tem1]][i][2] == 6 )
			if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if( TABLE[table[tem1]][i][2] == 1 && tem3 == 0 )
			if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if(  TABLE[table[tem1]][i][2] != 0 )
		tem3 += 1;
	}

	tem3 = 0;
	for (i=tem-2;i>-1;i--)
	{
		if( i%2!=0) continue;
			if( tem3 == 1 && TABLE[table[tem1]][i][2] == 6 )
				if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] )
				{
					check = 1;
					break;
				}
		if( TABLE[table[tem1]][i][2] == 1 && tem3 == 0 )
			if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if(  TABLE[table[tem1]][i][2] != 0 ) tem3 += 1;
	}

	tem3 = 0;
	for (i=tem1-2;i>-1;i--)
	{
		if( i%2!=0) continue;
		if( tem3 == 1 && TABLE[table[i]][tem][2] == 6 )
			if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if( TABLE[table[i]][tem][2] == 1 && tem3 == 0 )
			if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if(  TABLE[table[i]][tem][2] != 0 ) tem3 += 1;
	}

	tem3 = 0;
	for (i=tem1+2;i<19;i++)
	{
		if( i%2!=0) continue;
		if( tem3 == 1 && TABLE[table[i]][tem][2] == 6 )
			if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if( TABLE[table[i]][tem][2] == 1 && tem3 == 0 )
			if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] )
			{
				check = 1;
				break;
			}
		if(  TABLE[table[i]][tem][2] != 0 ) tem3 += 1;
	}

	if( tem1 > 1 )
	{
		if( TABLE[table[tem1-2]][tem-2][2] == 0 )
		{
			if( tem1 > 2 )
				if( TABLE[table[tem1-4]][tem-2][2] == 2 && TABLE[table[tem1-4]][tem-2][3] != TABLE[table[tem1]][tem][3] )
					check = 1;

			if( TABLE[table[tem1-2]][tem-4][2] == 2 && TABLE[table[tem1-2]][tem-4][3] != TABLE[table[tem1]][tem][3] )
				check = 1;
		}

		if( TABLE[table[tem1-2]][tem+2][2] == 0 )
		{
			if( tem1 > 2 )
				if( TABLE[table[tem1-4]][tem+2][2] == 2 && TABLE[table[tem1-4]][tem+2][3] != TABLE[table[tem1]][tem][3] )
					check = 1;

			if( TABLE[table[tem1-2]][tem+4][2] == 2 && TABLE[table[tem1-2]][tem+4][3] != TABLE[table[tem1]][tem][3] )
				check = 1;
		}
	}

	if( tem1 < 17 )
	{
		if( TABLE[table[tem1+2]][tem-2][2] == 0 )
		{
			if( tem1 < 16 )
				if( TABLE[table[tem1+4]][tem-2][2] == 2 && TABLE[table[tem1+4]][tem-2][3] != TABLE[table[tem1]][tem][3] )
					check = 1;

			if( TABLE[table[tem1+2]][tem-4][2] == 2 && TABLE[table[tem1+2]][tem-4][3] != TABLE[table[tem1]][tem][3] )
				check = 1;
		}

		if( TABLE[table[tem1+2]][tem+2][2] == 0 )
		{
			if( tem1 < 16 )
				if( TABLE[table[tem1+4]][tem+2][2] == 2 && TABLE[table[tem1+4]][tem+2][3] != TABLE[table[tem1]][tem][3] )
					check = 1;

			if( TABLE[table[tem1+2]][tem+4][2] == 2 && TABLE[table[tem1+2]][tem+4][3] != TABLE[table[tem1]][tem][3] )
				check = 1;
		}
	}

	if( check ) message_vision("$N���D"+HIG"���N�x�I�I��\n"NOR,this_player() );
}

int do_save()
{
	bb = 1;
	save();
	write("�O������\n");
	return 1;
}

int do_deploy()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	bb = 1; 

	if( ob->query("id1") )
		if( (present(ob->query("id1"),environment(ob))) || (present(ob->query("id2"),environment(ob))) )
			if( me->name() != ob->query("name1") && me->name() != ob->query("name2") && !ob->query("over") )
				return notify_fail("�����٦b�i�椤�A�A����ðʴѽL�I\n"); 

	if( !restore() ) return notify_fail("�A�ثe�S���������ݧ��C\n");

	setup();
	write("OK�I\n");
	return 1;
}

int do_lose()
{
	object ob,me;
	ob = this_object();
	me = this_player();

	if( me->name() != ob->query("name1") && me->name() != ob->query("name2") )
		return notify_fail("�A�èS���b�U�ѡC\n"); 

	if( ob->query("over") ) return notify_fail("�o�L�Ѥw�g�����F�C\n"); 

	if( bche == "" && rche == "" ) return notify_fail("�o�˴N�{��F?\n"); 

	message_vision(HIW"$N���Ĥ@�n��...�ڿ�F�I...��\n"NOR,this_player());
	ob->set("over", ob->query("name1") == me->name() ? ob->query("name2") : ob->query("name1") );

	return 1;
}

int do_help(string arg)
{
	if( arg == "cchess" )
	{
		write(@HELP
	
	�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w
	����H�ѡ]cchess�^
	�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w
	�U�l      �Gmove <��y��> <�a�y��> to <��y��> <�a�y��>
	���U      �Greset
	Ū�X�ݧ�  �Gdeploy
	�O���ݧ�  �Gcsave
	�Y��      �Gtoss
	�^�U      �Greview
	�{��      �Glose
	�ݴѽL    �G.
	
HELP
		); 
		return 1;
	}
}

int do_review()
{
	write("�ثe���L���Ѥl�C\n");
	write(aaa+"\n");
	return 1;
}

int do_reset()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	bb = 0;

	if( ob->query("id2") && !ob->query("over") )
		if( (present(ob->query("id1"),environment(ob))) && (present(ob->query("id2"),environment(ob))) )
		{
			return notify_fail("�����٦b�i�椤�A�A����ðʴѽL�I\n"); 
		}
//	if( restore() )
//	{
//		setup();
//        	message_vision( "$N��ѽL���s�\\�n�F�C\n",this_player());
//	}
//	else
//	{
		init_tab();
		message_vision( "$N��ѽL���s�\\�n�F�C\n",this_player());
//	}

	return 1;
}

int do_view(string arg)
{
	write(this_object()->long());
	return 1;
}