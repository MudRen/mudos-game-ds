#include <ansi.h>
inherit NPC;
void create()
{
set_name("���H�g", ({"cool"}) );
set("age",30);
set("long","�o�O�@�ӳQ�q���D���}�ǡA���y�M�͡A�����H�w�g�s�ۤv�������D
�F�A�h�ݥL�@���A�]�i�ন�������y�����@��C\n");
set("attitude", "aggressive");
set("level",22);
set_skill("dagger",70);
setup();
carry_object(__DIR__"wp/dagger")->wield();
}
