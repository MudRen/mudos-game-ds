inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬O�䳣 �ɦw�����������G��B���׶R��j�����A�䳣�P�F��������
������b�o�ӥ����i��A�A�ݨ쥫�����u�첳�h�A���U���U�˪�����B���G�B����
���A��B�O�u�c�s���n�A�D�`�a���x�n���C 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room7", 
  "west" : __DIR__"room1", 
  "south": __DIR__"room5",
  //"north": __DIR__"room4", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


