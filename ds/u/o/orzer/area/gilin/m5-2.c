inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A�n���e�����U�Y�e�i�A�o�̪��D���e�s���֡A���䦳�ۤ@�y���
�A�A���e�観�۳\�h�x�L��u�ۡA�ݨӧٳƴ��Y�A�o�̦��G���O���q�H
�i�H�a�񪺡A���D���ۤ��򤣴M�`���Ʊ��o�͡C
LONG
        );
        set("exits", ([
  "south" : __DIR__"m5-1",
  "north" : __DIR__"m5-5",
  "west" : __DIR__"m5-3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








