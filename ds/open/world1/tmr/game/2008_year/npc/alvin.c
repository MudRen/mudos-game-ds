#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
        set_name( "���", ({ "alvin mouse", "alvin", "mouse"}));
        set("long", @LONG
���O�u�����_�v�T�S�̤����Ѥj�A�O�i�R����߹��A
���ȷ|���ܡA�٫ܷ|�ۺq�C
LONG
        );
        set("level", 1);
        set("title", HIG"�����_"NOR);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 15);
        set("exp",1000);
	set("attitude", "peaceful");   //�ũM�� NPC�C
	set("no_kill",1);
	set("no_fight",1);

    setup();
}
