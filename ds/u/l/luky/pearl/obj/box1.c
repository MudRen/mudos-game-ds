#include <ansi.h>
//inherit F_CLEAN_UP;
inherit ITEM;
void create()
{
object ob, obj;
seteuid(getuid());
set_name("�j�Ƚc",({"box"}));
set("unit", "��");
set("long","�o�O�@�ӥi�H�˪F�誺�Žc�l�C�W���g�F�|�Ӧr:�귽�^��.\n");
set("no_sac", 1);
set("no_get", 1);
set_max_encumbrance(999999);
setup();
}
