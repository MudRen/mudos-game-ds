#include <ansi.h>
inherit ROOM;

void create()
{
 set("short",HIG"��P�ȴ�"NOR);
        set("long",@LONG
�b�s�D�W���F�\�[�A��M���e�@�G�A�@���ݰ_�ӫܵξA���ȴ̴N�b�A
���e�C���f����î�����\�ʵۡA�o�X�ӷL���F�F�n�C�����|�ۥ|�Ӥj�s»
��۵P�A�T�|�ӮȤH���bò�U�ͤѡA����L�������ǨӰ}�}�����s�n�A�F
�F�y���b�ȴ̭I��w�w�y�L�C
LONG
        );

         set("exits", ([
         "in": __DIR__"hotel_hall",
       "northup": __DIR__"path_1",
         ]));

        set("objects",([
              __DIR__"npc/traveler" : 1,
              ]) );
        
         set("item_desc",([
        "�s»":"�s»�W�H�����g�F�|�Ӥj�r"HIY"�y��P�ȴ̡z\n"NOR,
        "��î":"�Ӧ˽s´�Ӧ�����î�A������H���C\n",
         ]));
        set("outdoors","forest");
        
        setup();
        replace_program(ROOM);

 }