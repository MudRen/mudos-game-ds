//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�j�Ǩk��",({"play boy","boy"}));
set("level",25);
set("age",21);
set("long","�@�ӵL�ҨƬO���C�~�H, �@��鲴���_���˵۸��L���}�G���ܡC\n");
set("gender", "�k��");

        setup();
carry_object(__DIR__"book");
}
