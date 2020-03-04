// Room36.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;
string look_book(object me);

void create()
{
        set("short","�i�a�b��j");
        set("long", @LONG
�A�@���ݥh�A�|�س��O�Y�㺡�ت��Z�\�K�D�A��ӳo�̬O�Ѧa�|
�s��g�y���Ҧb�A�b��������W��ۤ@�����y(book)�A�W���g�ۡG�u
�Ѧa���k�v�A���T�Q½�\(read)���C

LONG
        );
        set("exits", ([
                "west": __DIR__"room35",
        ]));
        set("item_desc",([
        "book":(: look_book :),
        "table": "�o�i��l(table)���G�i�H����(push)�C\n",
        ]));


        set("objects" , ([
//            __DIR__"item/equip_shelf" : 1,
            __DIR__"item/item_box" : 1, // 2005.5.30 add by whoami
//            __DIR__"item/weapon_shelf" : 1,
        ]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
}
void init()
{
 add_action("do_push","push");
 add_action("do_read","read");
}

int do_read(string arg)
{
        if(arg=="book")
        {
                this_player()->start_more(@SKY_RULES
        
                           �i�Ѧa�|���W�j
�@�B  �Y��T�����

      ���������Ҿ֦����Ҧ�����(�N�O�����o)�A���i�H�[�J��L����
      �o�ˬO�קK�U�����������L�װ����C
      �P�ɤ]�U�줣�n�N�ۤv������ɵ��L�H�ϥΡC�ӭn�⨤��e���L
      �H�ɡA����POST�b���|�� Terra Board���G�A�Ѫ��ѥH�W�P�N��
      �N��Kickout��~�i�e���L�H�C
      �p�e���P������,�i�HPOST�bTerra Board�A�Ѫ��ѦP�N�C
      �t�~�T����N�������|�A�p�ۤv�������|�A���n�Ʊ楻�|���s��
      �A�A�Ӧ����n�����ɡA����POST�b Terra Board�g���ѷ|ĳ�q�L
      ��\�A�l�i���}���|�C
      �H�ϤW�z�W�w�̡A�N�v�X�ڡA�÷|�����D�M�w�O�_�[�H�q�r���C

�G�B  �Y�T�D��PK��L���a

      ���������T��PK��L���a�A���ѥ����o�X����O���ҥ~�C
      �өҦ�PK�������������a�A���ߧY�q���b�u�����ѤH���A�ñN��
      �pPOST�bTerra Board�A���e���������]�APKER ID�M�QPK��ID�A
      �Ӧb�u������,�����O�̤j��U�C
      �ӥ����N�C�X�q�r�¦W��A���������ҥi�����C�Y�QPK�ɡA�u�W
      �L���ѥH�W�i�����@�ҡA�h�гQPK�������ۦ�POST�L�{�A�ƫ�g
      ���ѩΥH�W�H���d�ҡA��N���C�J�q�r�¦W��C

      ���D��PK�H�~�A���������P�L�H����L�ȯɡA����POST�b
      Terra Board�Ѫ��ѥH�W�M�w��ʡA���i�ۦ�PK���C
      �H�ϤW�z�W�w�̡A�N�v�X���ڡA�å����D�����p�M�w�O�_�[�H�q
      �r�C

SKY_RULES
);
        return 1;
        }
        notify_fail("�A�Q�n�\\Ū����?\n");
        return 0;
}

string look_book(object me)
{
        return @SKY_BOOK
        
�A�ݨ�o���Ѫ��ʭ��W�g�ۡi�Ѧa���k�j�|�Ӥj�r�A�p�G�A�Q�F�ѳo��
�Ѫ����e�γ\�A�i�H�յ۾\Ū�ݬ�(read book)�C

SKY_BOOK;
}

int do_push(string arg)
{
        object room;
        if(!arg) return notify_fail("�A�n���ʤ���?\n");
        if(arg!="table" && arg !="��l") return notify_fail("�A�����D�n�������ӪF��C\n");
        if(this_object()->query("exit/down")) return notify_fail("��l�w�g�Q�������d��F�C\n");
        if( !room = load_object(__DIR__"cave") ) return notify_fail("�X�f�ä��s�b�C\n");
        set("exits", ([
                "west": __DIR__"room35",
                "down": __DIR__"cave",
]));
        room->set("exits/up",__FILE__);
        set("item_desc",([
        "book":(: look_book :),
        "table": "�o�i��l���G�O���[�e�~�Q�H������䪺�C\n",
        ]));
        create_door("down","�a���K�\\","up",DOOR_LOCKED,"skykey");
        room->create_door("up","�a���K�\\","down",DOOR_LOCKED,"skykey");
        message_vision("$N�ΤO�N��l�������, ���M�o�{�@���K�\\�l�C\n",this_player());
        return 1;
}

