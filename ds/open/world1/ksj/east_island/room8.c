#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","�Ʋz��");
  set("long",@LONG
�o�̬O�@������j���Ʋz���A���O�n�Y���Ʋz�i���֡A�ר�O��
�A��O�O�ҷs�A�n�Y�A����W�����F�U���\�I���W�٤λ����A�ѦҬ�
�ݧa(look menu)�C
LONG);
  set("exits",([ 
      "west":__DIR__"room12",
     ]));
  set("no_clean_up",0);
  set("light",1);
  set("item_desc", ([
      "menu" : "��P�W�g�F�U�خƲz���W�١A�Q�Y���ܴN�I�a�]order�^�C\n\n"
           +HIW"�l��(Suimono)                              �s(Sake)\n"NOR
           +"1.��l(Hamaguri-sui)         30            10.�M�s(Sake)                     100\n"
           +"2.�K�l(Tai-sui)�@�@�@�@      50�@�@�@  �@  11.�N�s(Shoshu)�@�@               130\n"
           +"3.�Y�ާl(Wakame-sui)�@�@     20            12.���s(Umeshu)                   150\n"
           +"                                           13.�¦̤j�u�C(Junmai daiginjo)    300\n"
           +HIW"����(Agemono)       \n"NOR
           +"4.���Ѥ�(Ebi-ten)�@�@�@�@    40            "HIW"�窫(Nebemono)\n"NOR
           +"5.����Ѱ�ù(Yasai-tenpura)  25            14.�س߿N(Sukiyaki)               180\n"
           +"                                           15.�R�R��(Shabushabu)             180\n"
           +HIW"�N��(Yakimono)"NOR"                             16.�e����(Fugu)                   250\n"
           +"6.�Q�N(Agu shioyaki)         60\n"         
           +"7.�����Q�N(Ebi shioyaki)     50\n"
           +"\n"
           +HIW"�{��(Tsukemono)\n"NOR
           +"8.��Ĭ���z(Siso-umebosi)     10\n"
           +"9.�Ǩ�(Natto)                10\n\n",
      ]));
  set("objects",([
      __DIR__"npc/food-master":1,
     ]));
  setup();
}            
