
inherit ROOM;

void create()
{
 set("short","�s���p�|");
        set("long",@LONG
�ӲӪ��s���b�p�|�ǽw�w�y�ʵۡA���誺�s�����@���սm�a���ۡA��
�O�@�Ӥp�r���A�s�u���r�����Y�y��o�̡A�b�o�̻E�����@�p���ڡA�H�Y
�N�y�J�a�U�C�����䪺�h��Ϊ��_�S�A����a�Τ]���Z�h�F�A���֤H�b��
�n���A�@�ɤs�L�����C
LONG
        );

         set("exits", ([
         "southdown": __DIR__"path_2",
//         "northup": __DIR__"path_t",
         "west": __DIR__"path_lake",
         ]));

         set("hide_exits", ([
         "east": __DIR__"grass",
         ]));

        set("objects",([
              __DIR__"npc/traveler" : 1,
               __DIR__"npc/obj/three-gentlemen_t" : 1,
              ]) );
        
        set("outdoors","land");
        
        setup();
        replace_program(ROOM);

 }