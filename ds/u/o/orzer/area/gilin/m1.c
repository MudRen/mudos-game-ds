inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A�V�L��誺�p���Ө�F�@�������������s���A�ݨ��٦��\�h����
�~�n�e�i�A���M�A�Q�n�ݤ@�U���B�����Y�A�i�O�o�]�������ӨS��k
�ݨ���q����B�A�ݨ��٦��o���F�C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"m2",
  "southwest" : "/open/world1/cominging/purple_sun/1f3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}




