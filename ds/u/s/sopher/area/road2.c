#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG"�v���˪L"NOR);
        set ("long", @LONG
���D�o�A��캥���}���F�A���G�ש�i�H�����o
�i�Ȫ��˪L�F�I�o�̦��@���P�l(sign)
LONG);  
        
        set("exits", ([
        "south": __DIR__"road3",
        "north": __DIR__"road1",
        ]) );
        set("outdoors","workroom.c");
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "sign": "
           �ѩ󦹴˪L�ۥj�w�M�I�X�F�W�A�U��ФH��
           �۷R�A�Ž�X���P�H�~���ϰ�A�H�K�o�ͦM�I�C
           �g�L�x�νլd�A��@�~�Ӧܤ֤w�g��300�󦺤`
           �R�סA�n�۬����C
                   
           �]�s�x�Ϊ�    �˺��[��@

           ���s��255�~7��7��
   ", ]) ); 
        setup();
        replace_program(ROOM);
}
