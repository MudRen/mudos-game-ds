inherit ROOM;

void create()
{
        set("short", "�n���O��");
        set("long", @LONG
��ߦb��f�n�誺�O��A�Υ۶����Ӧ��A�����Q�X�X�A�]�ߩΤ�
    �Ԥ��ήɷ|�U�N���ﰵ����J�䪺���ޡA���n���h�i�H�ݨ컷
    �����·¶���ִ������s�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room7",
  //"southwest" : __DIR__"room17",
  "northeast" : __DIR__"room16",
  //"east" : __DIR__"room38",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}

