#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",HIG"ST�DDoor�IFoodStreet"NOR);
          set("long",
          "�i�@�ɭ��~��j�A�A�b�o�̬ݨ�o�ӹq�l�i�ܪO�A�N���D�o�̴N�O�A\n"
          "�Q�n�h���a��F�A�o�̥��b�j�v�ŶǡA�A�߷Q�i�h�o�����~��A�ݬݦ���\n"
          "��S�O���n�Y�������Ӷ񺡧A�ŪŪ��{�l�C\n"
);
          set("exits", ([ /* sizeof() == 4 */
          "north":"/u/s/steps/area/street1.c",
          "southup":"/u/a/alickyuen/area/dst15.c",
          ]));
          set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/woman" : 1,
]));
          set("chat_chance", 4);
          set("chat_msg", ({
                HIY"���j�a�n�A�@�ɭ��~��s�}���A�h�¤j�a�����\n"NOR,
                HIY"���h�إ@�ɬ������b���~�󤺡A�j�a�ָոէa��\n"NOR,
        }));
setup();
}
