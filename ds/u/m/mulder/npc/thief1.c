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
message("world:world3:vision",
HIM"                   �Ƹ˧��H���s���{���e�I��X�æb�h�̪��T�ϡC\n\n"+NOR
	,users());
environment(this_object())->set("war",1);
::die();
}

