#include <ansi.h>
//inherit F_CLEAN_UP;
inherit ITEM;
void create()
{
object ob, obj;
seteuid(getuid());
set_name("大紙箱",({"box"}));
set("unit", "個");
set("long","這是一個可以裝東西的空箱子。上面寫了四個字:資源回收.\n");
set("no_sac", 1);
set("no_get", 1);
set_max_encumbrance(999999);
setup();
}
