#include <ansi.h>
inherit ROOM;

string *room_long = 
({
//1
"�o�̬ݰ_�Ӽs�j������A�������H�ݰ_�ӡA�|ı�o�j�۵M������ 
�C�A�q�q��ť��@�Ǻq�R�n�A�A���F�@�}�l�A�A�[��F�Ҧ��a��A��
�O�d���X�q���O���Ӫ��q���n���C\n",//2
"�b����A���ǧ����R�p����A�S�����󪺧n���n�A�N�n�����b�j
�۵M�̳o�򪺦w�����R�A���L�j�H�٤����ɭ��B�e�����R�A�A�L�k�w
���U�@��|�o�ͤ���ơA�ҥH���褺�߷Pı�xŸ���w�C\n",});

string ROOM_LONG()
{
        return room_long[random(sizeof(room_long))];
}
