
inherit ROOM;

void create()
{
 set("short","�s���p�|");
        set("long",@LONG
�X�����ఱ�b�A���Ǧn�_���ݵۧA�A���A�Q����ɤS���J�L���A�A��
���b�@�����R�p�D�W�C
LONG
        );

         set("exits", ([
         "southwest": __DIR__"path_1",
         "northup": __DIR__"path_t",
         ]));

        set("outdoors","land");
        
        setup();
        replace_program(ROOM);

 }