#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
        set_name("�U����" , ({ "jin lai wan","wan" }) );
        set("level",3);
        set("no_fight",1);
        set("race","�H��");
        set("gender","�k��");
        set("age",45);
set("talk_reply","�o�̯ണ��(withdraw)�B�s��(deposit)�H�άd��(balance)");
        set("long","�L�O�U���������ѪO�C\n");
        setup();
}
void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}
