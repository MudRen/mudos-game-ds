inherit ROOM;

void create()
{
        set("short", "�_���O��");
        set("long", @LONG   
��ߦb��f�_�誺�O��A�Υ۶����Ӧ��A�����Q�X�X�A�]�ߩΤ�
    �Ԥ��ήɷ|�U�N���ﰵ����J�䪺���ޡA���ǳ��ȳ��w�b�o�Ӧa
    �賨���C 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "southeast" : __DIR__"room9",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


