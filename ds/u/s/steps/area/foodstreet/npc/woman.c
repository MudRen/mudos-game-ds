#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�k�ŶǤH��", ({"woman"}) );
        set("long", "�o�O���~�󪺤k�ŶǤH���C\n");
        set("race", "�H��");
        set("age", 17);
        set("level", 15);
        set("chat_chance", 10);
        set("chat_msg", ({
                HIY"���j�a�n�A�@�ɭ��~��s�}���A�h�¤j�a����I��\n"NOR,
                HIY"���h�إ@�ɬ������b���~�󤺡A�j�a�ָոէa�I��\n"NOR,
        }));
setup();
}
