#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("���ѱC�C" , ({"old woman cheng","old","woman","cheng"}) );
        set("level",5);
        set("race","�H��");
         set("gender","�k��");
        set("age", 63);
        set("no_fight",1);
        set("long",@LONG
�o�O�o�̷̳O�����ѱC�C�A�`�`�|���ߦa�۫ݥ~�a�Ӫ��ȫȡA���X��
�b�~���ȫȤ]��P���즳�p�b�a�m�몺�ŷx�C
LONG);
        set("sell_list",([
         __DIR__"obj/come_best" : 20,
         __DIR__"obj/oreo" : 20,
         __DIR__"obj/fantasy_pill" : 20,
        ]) );
        setup();
}
void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}
