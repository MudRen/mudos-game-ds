#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�۴Y"NOR);

 set("long",@LONG
�A���b�۴Y��, ��Ǫ��۾��W���B�J�l�ޤF�A, �A�ݤF�ݥ۾�, ����
�O�@���i�Ͱ������j���C���b�ѻ�, ���ѧ@��s��, �|�P�h���\�h�����W
��������¶�b�����, �a���W�h���\�h�é_���~�Ϊ�����M, �ΧC�Y�ڪA
, ���A���@, ���L�@����ܤF��j���L�񪺷q�N, �A�@�Ӭݤj��, �䲴��
��������, ���i�l�Ӯ𮧤���, í���Ӥ��S�W�~, �ӥk��h�O�@���۾�, 
�W����۴X�Ӥj�r...
LONG
    );
 set("exits",([ "west":__DIR__"birdpilla5", 
                "east":__DIR__"birdpilla8",
    ]));
 set("item_desc",(["�۾�":"
                �o�O�@�����ƪ��۾�, �W����۴X�Ӽ⾥�몺�j�r\n

                   "RED"�i                ��"NOR"\n
                   "RED"��                ��"NOR"\n
                   "RED"��                �@"NOR"\n
                   "RED"��                ��"NOR"\n
                   "RED"�T                ��"NOR"\n
                   "RED"�d                �Z"NOR"\n
                   "RED"��                �L"NOR"\n

                �ݨ�۴X�ӻ���z�����j�r, �A���T�Q����~�ѱ�\n
                ��������, �O�󵥭���!!���Φܦ�, �A�E�ʪ�����\n
                �ۤv, �A�w�g�������T�w�A�����n�θ��Z�L�\\

                �[����~�Ĥ@�j��-"HIC"�ѱ���"NOR"�F!!\n",
  ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

