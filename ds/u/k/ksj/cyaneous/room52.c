inherit ROOM;

void create()
{
        set("short", "�H�ۤl��");
        set("long", @LONG
�o�̬O�o�V�~���D���A���M��������O�ͻ\�����������A���O�i�H�ݱo�X�ӥH
    �e�O���e�s���j���A�o��������i�H��F�䳣 �ɦw�������C 
        [���P�F�n�誺���n�ڼo�V�۳s�A�ȥ����u�A�G���}��]
LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  //"northwest" : __DIR__"room50",
  //"east" : "/open/world1/jangshow/barer/road1",
  //"north" : __DIR__"room34",
  "west" : __DIR__"room51",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}
