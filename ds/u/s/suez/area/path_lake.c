
inherit ROOM;

void create()
{
 set("short","�p���p");
        set("long",@LONG
�s�u�u�ۤs���y��o�̡A�稵�r�ޡA�[�Ӥ[���K�b�o�̫��X�F�@�Ӥp
���p�A�J�Ӥ@�ݡA���p���٦��p���b��۩O�I�A���T�S���B��ѥH�[����
�ߡA�߶}�Z�L�����������A�ɱ��ɨ��o�@�~�緽�������C
LONG
        );

         set("exits", ([
         "east": __DIR__"path_t",
         ]));
        set("objects",([
              __DIR__"npc/fong-wu-yen" : 1,
              ]) );
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
