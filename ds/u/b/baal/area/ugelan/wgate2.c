#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"�վB�����w����j���w����"NOR);
        set("long", @LONG
�վB����������p�F��Q���ءA�ҥH�����o�q�N�����G
�D�@��A��������ݨ�ۤ@�T���j���B�J�A�H���y�A�_�۸�
���ۡA�b���D��Ǥ�������ģ�U�Ϯg��ģ�������~�A��ǽ�
�ߵۼƭӪ��J���A�u�í̦b���ӨӦ^�^�����޵ۡA�¿p����
�^���A�]�p���l�l�F�_��...
LONG
        );
        set("exits", ([ 
            "west": __DIR__"wgate",
            "east": __DIR__"wgate3",
            ]));
                                 set("item_desc",([
"�B��":
"�s�I�I�ƥH�ʭp���s�I�Ĥ@�ӬM�J�A��î���N�O�o�Ǹ�ѯ��@�_�Ө�o�@�W���ͪ�
�A�o�O�ӥ��j���@�~�A�yø�۷R�Z�������Ԫ��E�P���ΡA�s��۪Ť��x�U�A�u�@��
������M�G�۾�Ӷ�S�i����A�Z���]���ʹ�����(Kaeploner)�B���z����(God of
Wisdom)�^�S��(Interser)��O�q����(God of Strength)�d�ߦw(Karian)���O���b
�U�۪����A���ߥ��F���ѻP�o���Ԫ��A�j�a���O�԰�������A�o�O���ڪ��Ԫ��A
���O���p���H���A�ƦܬO�@�V�H�����l�����ƪ����F�ү�ѻP���A��ӯB��N��b
����W�A���M�B�褺���j�p�����L�k�ۤ�A�A���`�`���P����ۤv�����p...\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

