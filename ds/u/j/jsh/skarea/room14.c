inherit ROOM;

void create()
{
        set("short", "�H�۸�");
        set("long", @LONG
�o�̬O�o�V�~���D���A���M��������O�ͻ\���������A���O�i�H�ݱo�X�ӥH
�e�O���e�s���j���A�o��������i�H��F�䳣 �ɦw�������C 
[���P�F�n�誺���n�ڼo�V�۳s�A�ȥ����u�A�G���}��]
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"east" : __DIR__"room7",  
  "northwest" : __DIR__"room13", 
  //"south": __DIR__"room9",
  //"north": __DIR__"room8", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


