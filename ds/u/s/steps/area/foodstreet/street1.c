#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"ST�DStreet�IFoodStreet"NOR);
        set("long",
        "�@���i�ӳo�̡A�A�N�ݨ�U���U�˪��@�ɭ^���ɦb��î�A�ӥB����\n"
        "�����N��[���H�ήe�C�o�̪����쳣�w�g�t���h�����F�H�A�A�N�i�H�ո�\n"
        "�A����l���U�ӡA�����o�̭��������D�C\n"
);
        set("exits", ([ /* sizeof() == 4 */
          "north":"/u/s/steps/area/street2.c",
          "east":"/u/s/steps/area/counter1.c",
          "west":"/u/s/steps/area/counter2.c",
          "south":"/u/s/steps/area/door.c",
        ]));
        setup();
}
