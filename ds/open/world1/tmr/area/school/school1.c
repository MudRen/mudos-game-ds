#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ڤ۰ϰ�s��Ы�"NOR);

set("long", @LONG

[1;31m                  �d�d�d�d�d�d�d�d�d�d�d�d�d�d�d
                ����������������������������������
             ����������������[m[47;30m�w��Y�{[1;40;31m����������������
[0m�u�q�q�q�q�q�q�q�q[31m�m�n[1;33m�z�w�w�w�{�x�z�w�w�w�{[0;31m �m�n[m�q�q�q�q�q�q�q�q�t
�u�r�r�r�r�r�r�r�r[31m�m�n[1;33m�x      �x�x�x      �x[m[31m �m�n[m�r�r�r�r�r�r�r�r�t
[1m��[36m  .[32m"[37m   "    '[m[31m   �m�n[1;33m�x      ���x��      �x[m[31m �m�n[1;37m'�ȫȪ`�N!!     ��
��          . "[0;31m   �m�n[1;33m�x      �x�x�x      �x[0;31m �m�n[1;37m �Фų�W�~�X   ��
�� "    .[35m"[32m    `[31m   �m�n[33m�|�w�w�w�}�x�|�w�w�w�}[31m �m�n[37m,�H�K����!      ��
�r�w�w�w�w�w�w�w[31m�y���o[33m�w�w�w�w�w�r�w�w�w�w�w[31m|���o[37m�w�w�w�w�w�w�w�w�r[m

  �w��[�J�ڤۤC��!! �A�ثe����m�O�b�ڤۮ��]�����s��Ы�.
	
  �A���Ť����o�ئa��P����_, �A���U�F�A���|�P, �o�{�o�̰�
�F�X���j��(books)�M�@���K�s���i�ܵP(sign) �H�~�u���@����s��
��, �A�J�ӬݤF�@��, ��M�o�̬O����X�T�f���s��оǥΪ��]�\�A
�i�H�ݬ�(look��l)�i�ܵP�Υj��, �۫H�A�|���ҵo�{��....

[ ����: �n�ݳo�̪��ѴN��J look books �άO l books ]

LONG
    );
 set("exits",([
                "east":__DIR__"school2.c",
    ]));
 set("item_desc",([
        "books":"�A�ݤF�ݳo�ǹЫʤw�[����, �o�{���̷ӵ۽s���ƦC, �A�Q���ӱq�Ĥ@
��(book_1)�}�l�ݰ_.\n",
        "sign":"�o���K�s���i�ܵP�g��:!! �w��ϥηs��Ы� !!.\n",
        "book_1":@BOOK1

  �o�G���ѥD�n�O�n�i�D�A�@�Ƿs�����Ӫ��D���`��, ����, Ds���
����mud�@��, �s��ȥ��n���ݤ@�ݧڭ̪��W�h (help rules), �]��
�A�Ҫ���mud�i�H���ƶ��i��Ds���i�H,�ҥHŪ�W�h�i�H�קK�A�L�Τ�
�ǿ�, �ݨ�o��, �A���Ӥw�g���D�o���ѬO�n�ЧA�p��ϥ�help, �A
�i�H�b���q���p�U������Jhelp, ���U�ӷ|�X�{�@��help�D�D, �A�i
�H��help xxx�A�h���D�@�ǸԱ�, �n�F..�o�@���ѱЧA�p���help, 
�N��o��, ���U�ӧA�N�i�H�ݲĤG����(book_2)�F.���A�@������...

BOOK1
,
        "book_2":@BOOK2
        
  �n�F, �o�@���ѬO�n�ЧA�p��M�䥦�����a���, �����A�i�H�ϥ�
<tchat> ��䥦�Ҧ����a���, �]�N�A�O�A�����ܩҦ����a���|�ݨ�
, ���ۧA�]�i�H�ϥ�<say> �Ӹ��A�b�P�@�檺�H���, �u���A�o��
���H�~�ݪ���, <tell [���a�W]>�i�H�ϧA���T���u�Q�o�ӤH�ݨ�, 
 <shout> ���ϥΰ򥻤W�M <tchat> �t���h, ���ӫ�ĳ�s��ϥ�....
 ok! �o���ѴN�즹����....�Ʊ��A�������U....

BOOK2
,
        ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();

}

