#include <ansi.h>
inherit NPC;
void create()
{
set_name("���H", ({"man"}) );
set("age",30);
set("long","�����O�q���Ӫ��A�Q���������H���C\n");
set("level",10);
setup();
}

void die()
{
shout("\n\n"
+HIM"                   �Ƹ˧��H���s���{���e�I��X�æb�h�̪��T��\n\n"NOR);
write("\n\n"
+HIM"                   �Ƹ˧��H���s���{���e�I��X�æb�h�̪��T��\n\n"NOR);
environment(this_object())->set("war",1);
::die();
}

