#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�˪ŮѰ|"NOR);

 set("long",@LONG
�A���Ť����o�ئa��P����_, �A���U�F�A���|�P,�o�{�o�̰��F�X���j��(books)
�M�@���K�s���i�ܵP(sign)�H�~�u���@����s���, �A�J�ӬݤF�@��, ��M�o�̬O����X
�T�f���s��оǥΪ��]�\�A�i�H�ݬ�(look��l)�i�ܵP�Υj��, �۫H�A�|���ҵo�{��....
LONG
    );
 set("exits",([
                "east":__DIR__"school2.c",
    ]));
 set("item_desc",([
        "books":"�A�ݤF�ݳo�ǹЫʤw�[����, �o�{���̷ӵ۽s���ƦC, �A�Q���ӱq�Ĥ@
��(book_1)�}�l�ݰ_.\n",
        "sign":"�o���K�s���i�ܵP�g��:!! �w��ϥηs��Ы� !!.\n",
        "book_1":"�o�G���ѥD�n�O�n�i�D�A�@�Ƿs�����Ӫ��D���`��, ����, Ds��䥦��
mud�@��, �s��ȥ��n���ݤ@�ݧڭ̪��W�h(help rules), �]���A�Ҫ���mud�i�H��
�ƶ��i��Ds���i�H, �ҥHŪ�W�h�i�H�קK�A�L�Τ��ǿ�, �ݨ�o��, �A���Ӥw�g��
�D�o���ѬO�n�ЧA�p��ϥ�help, �A�i�H�b���q���p�U������Jhelp, ���U�ӷ|�X
�{�@��help�D�D, �A�i�H��help xxx�A�h���D�@�ǸԱ�, �n�F..�o�@���ѱЧA�p��
��help, �N��o��, ���U�ӧA�N�i�H�ݲĤG����(book_2)�F.���A�@������....\n",
        "book_2":"�n�F, �o�@���ѬO�n�ЧA�p��M�䥦�����a���, �����A�i�H�ϥ�chat
��䥦�Ҧ����a���, �]�N�A�O�A�����ܩҦ����a���|�ݨ�, ���ۧA�]�i�H�ϥ�say �Ӹ��
�A�b�P�@�檺�H���, �u���A�o�檺�H�~�ݪ���, tell <���a�W>�i�H�ϧA���T���u�Q�o��
�H�ݨ�, shout ���ϥΰ򥻤W�Mchat �t���h, ���ӫ�ĳ�s��ϥ�.... ok! �o���ѴN�즹��
��....�Ʊ��A�������U....\n",
        ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
void init() { this_player()->set("not_newbie",1); }
