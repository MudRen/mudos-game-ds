#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(MAG"��������"NOR ,({ "Dead-God Bless ring","ring" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
�o�O�ǻ��������ѵ��C�s�L��, �]�P͢���������Ұe������!
LONG
     );
                set("unit", "��");
                set("value",99999);
                set("material", "silver");
                set("armor_prop/int",20);
                set("armor_prop/str",20); 
                set("wear_msg", MAG"$N���X$n����W�@��, �@�ѳ��˴˪��Pı�B�W���Y...\n"NOR); 
                set("armor_prop/id",({"dead god","god"}));
                set("armor_prop/name",({"����"}));
                set("armor_prop/short",({"����(dead god)"}));
                set("armor_prop/long",({"
                          �d�f�h�i�i�h�f�d
                        �h�i�i�i�i�i�i�i�i�h
                       �i�i�i�i�i�i�i�i�i�i�i
         �e          �i�i�e�i�i�i�i�i�i�i�e�i�i
         �l         �i�i�i      �i�i     �i�i�i
         �i        �m�i         �i         �i�i
         �e         �i                       �i
      �e �e �e �d  �i                       �i
      �m �m �m �f   �i          �i          �i
   �e�i�m�i �i �m   �i�e     �i  �i     �e�i
  �i�e�e�e�e�e�e�e   �d �i�e�i      �i�e�i �d
 �i �i �i �i �i �i    �i�e�i�i      �i�m�e�i
  �m�i�i�i�i�i�i�i      �i �i�i    �m�m �i
 �i �i�i�i�i�i�i        �i  �m�m�f �m�m �i
    �i�i�i�i�d�m        �i            �i
      �i�d �i�i           �i �m�m �m�m�i
      �i�i �i�i              �i�i�i�i


"}) );
                      }
        setup();
}

