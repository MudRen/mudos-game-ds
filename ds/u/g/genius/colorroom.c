#include <room.h>
#include <ansi.h>
#include <ansi2.h>
inherit ROOM;
void create()
{
set("short",HIG"��"HIY"�C"HIC"��"HIR"��"HIM"��"HIB"�s"HIW"��"NOR);
set("long",    "\n�o�̥R���F�U���U�˪��C��\n\n"
               "�o�O"BLK"$BLK$��"NOR"�@�@�@�o�O"NOR"$NOR$��\n"NOR
               "�o�O"RED"$RED$��"NOR"�@�@�@�o�O"HIR"$HIR$��\n"NOR
               "�o�O"GRN"$GRN$��"NOR"�@�@�@�o�O"HIG"$HIG$��\n"NOR
               "�o�O"YEL"$YEL$��"NOR"�@�@�@�o�O"HIY"$HIY$��\n"NOR
               "�o�O"BLU"$BLU$��"NOR"�@�@�@�o�O"HIB"$HIB$��\n"NOR
               "�o�O"MAG"$MAG$��"NOR"�@�@�@�o�O"HIM"$HIM$��\n"NOR
               "�o�O"CYN"$CYN$��"NOR"�@�@�@�o�O"HIC"$HIC$��\n"NOR
               "�o�O"WHT"$WHT$��"NOR"�@�@�@�o�O"HIW"$HIW$��\n\n"NOR

               "�o�O"BBLK"$BBLK$��"NOR"�@�@�@�o�O"HBWHT"$HBWHT$��\n"NOR
               "�o�O"BRED"$BRED$��"NOR"�@�@�@�o�O"HBRED"$HBRED$��\n"NOR
               "�o�O"BGRN"$BGRN$��"NOR"�@�@�@�o�O"HBGRN"$HBGRN$��\n"NOR
               "�o�O"BYEL"$BYEL$��"NOR"�@�@�@�o�O"HBYEL"$HBYEL$��\n"NOR
               "�o�O"BBLU"$BBLU$��"NOR"�@�@�@�o�O"HBBLU"$HBBLU$��\n"NOR
               "�o�O"BMAG"$BMAG$��"NOR"�@�@�@�o�O"HBMAG"$HBMAG$��\n"NOR
               "�o�O"BCYN"$BCYN$��"NOR"�@�@�@�o�O"HBCYN"$HBCYN$��\n"NOR
);


      set("exits", ([
      "west": "/u/g/genius/roomenter.c",
      ]));
      set("light",1);
}

