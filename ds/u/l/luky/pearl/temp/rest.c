// guild.c���vendor.c

#include <path.h>
inherit ROOM;
inherit F_AUTOLOAD;
void create()
{
set("short","�����R���Ȧs�ө�");
set("light",1);
set("objects",([
LUKY+"pearl/obj/rice1":100,
LUKY+"pearl/obj/meat":100,]));
set("no_clean_up",1);
setup();
}
