inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�p�p���ж����A������m�ۤ@�i���Y��l�A��l�W������o�X�L
�z�����~�A��ģ�ۥ|�P�A���F��l�~�A�b�ж��������٩�ۤ@�i�ɡA
�ݳo�Ӽˤl�A�o�̦��G���H�~��C
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"room-10",
        ]));
        set("objects",([
                   __DIR__"../npc/beng" : 1,
                 ]) );
        set("light",1);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}
