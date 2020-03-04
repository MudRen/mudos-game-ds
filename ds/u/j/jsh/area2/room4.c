#include <room.h>

inherit ROOM;

inherit DOOR;
void create()
{
          set("short", "�j�U");
          set("long", @LONG 
  �A����@�Ӧ����u���a��A��ӳo�̬O�o�}�ު��j�U�A�b�j�U����n�賣
  �O�H�զ⬰�D�A�ӥB�\���D�`����A�٬O�H�K���}���Φ��U�h�ƪ��A�Q���o��
  ���H�w�j�j�����Y�C
LONG
           );
           set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"masterroom", 
  "west" : __DIR__"master2room",
  "east" : __DIR__"room3",  
  "down" : __DIR__"under/startroom",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"wang" : 1,
]));      
  set("no_clean_up", 0); 
  set("no_pick",1);
  setup(); 
  create_door("down","������","up",DOOR_LOCKED,"whitekey"); 
}

