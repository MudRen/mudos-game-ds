inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A�L�F��誺�ﯸ�A�~�򩹤U�Y�e�i�A�Ů𤤶ǨӭY�����L���H��
�]�\�O���Ӥ[����ı�A�e�褣���D������F�赥�ݵۡA�ݨ����ӧ֭n��
��Y���F�A�e���R�ĵL��A�Pı�S������ͮ�C
LONG
        );
        set("exits", ([
  "northdown" : __DIR__"m6",
  "south" : __DIR__"m5-2",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}






