/* write by -Acme-
*/

inherit ITEM;

void create()
{
     switch( random(100) ) {
         case 0..10:
             set_name("���y", ({ "gold ball", "ball" }) );
             set_weight(300);
             set("kind", "gold");
             set("power", random(10)+1);
             set("value", random(4000)+1);
             set("long", "�@���ª����y���p�y�A��������γ~�C");
             break;
         case 11..31:
             set_name("�Ȳy", ({ "silver ball", "ball" }) );
             set_weight(250);
             set("kind", "silver");
             set("power", random(10)+1);
             set("value", random(3000)+1);
             set("long", "�@���»ȥ��y���p�y�A��������γ~�C");
             break;
         case 32..62:
             set_name("�ɲy", ({ "brass ball", "ball" }) );
             set_weight(200);
             set("kind", "brass");
             set("power", random(10)+1);
             set("value", random(2000)+1);
             set("long", "�@���»ɥ��y���p�y�A��������γ~�C");
             break;
         default:
             set_name("�K�y", ({ "iron ball", "ball" }) );
             set_weight(100);
             set("kind", "iron");
             set("power", random(10)+1);
             set("value", random(1000)+1);
             set("long", "�@�����K���y���p�y�A��������γ~�C");
             break;
     }

     set("unit", "��");
     setup();
}
