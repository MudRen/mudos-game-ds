inherit ROOM;

void create()
{
        set("short", "�B�F����");
        set("long", @LONG 
�A�@�Ө�o�̴Nť��n�����s���n�A�C�ӤH�������ۧA�A�K���A
�ݤ��L��ӡA�b���u�쪺�O������Ѫ��A�ݨ�L�j�M�����A�X���A��
�����ױ��i�u���A����|���A���u�O�ͷN�̦n���@�u�C

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"store1", 
  "west" : __DIR__"store4", 
  "north" : __DIR__"store5",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"sellman2" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

