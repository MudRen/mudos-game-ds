#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����s��");
        set("long", @LONG
�o�̬O�ѫ��������s���A�A�i�H�ݨ��H�ӤH�����۷��c�a�A�ѫ��]
�Ѵ����Y�ӱa�ӤF�\�h���C�Ȩӳo�C���A�ϱo�ѫ����t���o�i�A�b�n
���ӥ��K�Q�A���_�h�i��Ѵ�A�s�������٦��ӧi�ܵP�C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "�i�ܵP" : "�o�O�a��x�b�o�ҳ]���G�i��A�ݰ_�Ӭ۷��s�A���G�٥����ϥΡC
",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/traveler" : 1,
  __DIR__"npc/traveler1" : 2,
]));
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"plaza4",
  "west" : __DIR__"plaza",
  "south" : __DIR__"plaza2",
  "east" : __DIR__"plaza3",
]));
        set("no_clean_up", 0);
        set("outdoors","land");

        setup();
}
