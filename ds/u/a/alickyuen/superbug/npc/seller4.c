#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�`��" , ({ "chang wen","chang","wen" }) );
        set("level",10);
        set("race","�H��");
        set("age", 30);
        set("long","�L�O�b�o���t���θ̤u�@�����u�A�A�i�H�V�L�R�A�Q�Y���F��C\n");
set("sell_list", ([
__DIR__"obj/sandwich" : 1,
]));
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
