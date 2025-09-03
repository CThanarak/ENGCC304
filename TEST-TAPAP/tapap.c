#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* ---------- สินค้า: ชื่อ, ราคา, สต็อกเริ่มต้น ---------- */
    const char *names[7] = {
        "โค้ก", "น้ำเขียว", "อเมริกาโน่", "ลาเต้หวานเจี๊ยบ",
        "เมล็ดทานตะวัน", "ถั่วแปบ", "จิ้นส้มหมก"
    };
    /* ตามโจทย์ในแผนภาพ: โค้ก 10, น้ำเขียว 12, อเมริกาโน่ 30, ลาเต้ 35, เมล็ดทานตะวัน 13, ถั่วแปบ 20, จิ้นส้มหมก 15 */
    int price[7] = {10, 12, 30, 35, 13, 20, 15};
    int stock[7] = {10, 10, 10, 10, 10, 10, 10};
    int sale[7]  = {0, 0, 0, 0, 0, 0, 0};
    int expired[7] = {0, 0, 0, 0, 0, 0, 0};
    /* วันหมดอายุของแต่ละสินค้า (จาก Flowchart) */
    int expDays[7] = {30, 30, 15, 15, 15, 7, 5};

    /* ---------- คลังเงินเริ่มต้นในตู้ ---------- */
    int billDen[5] = {1000, 500, 100, 50, 20};
    int billCnt[5] = {0, 2, 10, 5, 20};
    int coinDen[4] = {10, 5, 2, 1};
    int coinCnt[4] = {20, 20, 15, 30};

    /* ---------- คำนวณวันใช้งานและเช็กหมดอายุ ---------- */
    int fillDay = 0;
    int i = 0;

    printf("กรอกวันเติมของ (0-30): ");
    if (scanf("%d", &fillDay) != 1) {
        printf("อินพุตไม่ถูกต้อง\n");
        return 1;
    }
    if (fillDay < 0) fillDay = 0;
    if (fillDay > 30) fillDay = 30;

    srand((unsigned)time(NULL));
    int useDay = (rand() % 30) + 1;  /* วันใช้งานสุ่ม 1..30 */
    printf("วันใช้งาน (สุ่ม): %d\n", useDay);

    int usedDays = useDay - fillDay;
    if (usedDays < 0) usedDays = 0;

    /* ถ้าเกินวันหมดอายุให้ตัดสต็อก = 0 และนับหมดอายุ +1 */
    for (i = 0; i < 7; i++) {
        if (stock[i] > 0) {
            if (usedDays > expDays[i]) {
                stock[i] = 0;
                expired[i] += 1;
            } /* end if */
        } /* end if */
    } /* end for */

    /* ---------- เลือกสินค้า (ได้หลายชิ้น) ---------- */
    int cart[7] = {0, 0, 0, 0, 0, 0, 0};
    int selecting = 1;

    do {
        int cat = 0;
        printf("\nเลือกประเภทสินค้า: 1=เครื่องดื่ม, 2=ขนม, 0=จบการเลือก: ");
        if (scanf("%d", &cat) != 1) {
            printf("อินพุตไม่ถูกต้อง\n");
            return 1;
        }

        if (cat == 0) {
            break;
        } else if (cat == 1) {
            int ch = 0, idx = -1;
            printf("เครื่องดื่ม: 1)โค้ก  2)น้ำเขียว  3)อเมริกาโน่  4)ลาเต้หวานเจี๊ยบ  : ");
            if (scanf("%d", &ch) != 1) {
                printf("อินพุตไม่ถูกต้อง\n");
                return 1;
            }
            if (ch == 1) idx = 0;
            else if (ch == 2) idx = 1;
            else if (ch == 3) idx = 2;
            else if (ch == 4) idx = 3;

            if (idx == -1) {
                printf("เมนูไม่ถูกต้อง\n");
            } else {
                int remain = stock[idx] - cart[idx]; /* เหลือให้หยิบได้กี่ชิ้น (ยังไม่ตัดสต็อกจริงจนกว่าจะจ่ายเงินสำเร็จ) */
                if (remain > 0) {
                    cart[idx] += 1;
                    printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", names[idx], cart[idx]);
                } else {
                    if (stock[idx] > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", names[idx]);
                    else printf("%s หมดสต็อก/หมดอายุ\n", names[idx]);
                }
            }
        } else if (cat == 2) {
            int ch = 0, idx = -1;
            printf("ขนม: 1)เมล็ดทานตะวัน  2)ถั่วแปบ  3)จิ้นส้มหมก  : ");
            if (scanf("%d", &ch) != 1) {
                printf("อินพุตไม่ถูกต้อง\n");
                return 1;
            }
            if (ch == 1) idx = 4;
            else if (ch == 2) idx = 5;
            else if (ch == 3) idx = 6;

            if (idx == -1) {
                printf("เมนูไม่ถูกต้อง\n");
            } else {
                int remain = stock[idx] - cart[idx];
                if (remain > 0) {
                    cart[idx] += 1;
                    printf("เพิ่ม %s 1 ชิ้น (ในตะกร้า %d ชิ้น)\n", names[idx], cart[idx]);
                } else {
                    if (stock[idx] > 0) printf("%s เหลือไม่พอสำหรับเพิ่มในตะกร้า\n", names[idx]);
                    else printf("%s หมดสต็อก/หมดอายุ\n", names[idx]);
                }
            }
        } else {
            printf("เมนูไม่ถูกต้อง\n");
        }

        printf("เลือกต่อหรือไม่? (1=ต่อ, 0=จบการเลือก): ");
        if (scanf("%d", &selecting) != 1) {
            printf("อินพุตไม่ถูกต้อง\n");
            return 1;
        }
    } while (selecting == 1);

    /* สรุปรายการที่เลือก และคำนวณยอดรวม */
    int total = 0;
    int hasItem = 0;
    printf("\n=== รายการสินค้าในตะกร้า ===\n");
    for (i = 0; i < 7; i++) {
        if (cart[i] > 0) {
            int line = cart[i] * price[i];
            printf(" - %s x %d = %d บาท\n", names[i], cart[i], line);
            total += line;
            hasItem = 1;
        }
    }
    printf("รวมราคาสินค้า: %d บาท\n", total);

    if (!hasItem) {
        printf("ไม่มีรายการสินค้า\n");
        /* ไปสรุปท้ายโปรแกรม */
    } else {
        /* ---------- ชำระเงิน ---------- */
        int method = 0;
        printf("\nเลือกวิธีชำระ (1=เงินสด, 2=สแกนจ่าย QR): ");
        if (scanf("%d", &method) != 1) {
            printf("อินพุตไม่ถูกต้อง\n");
            return 1;
        }

        if (method == 2) {
            /* จ่ายด้วย QR */
            int paid = 0;
            do {
                printf("** แสดง QR เพื่อชำระ %d บาท **\n", total);
                printf("โอนสำเร็จหรือไม่? (1=ใช่, 0=ไม่): ");
                if (scanf("%d", &paid) != 1) {
                    printf("อินพุตไม่ถูกต้อง\n");
                    return 1;
                }
                if (paid != 1) {
                    int again = 0;
                    printf("การชำระล้มเหลว ต้องการลองใหม่ไหม? (1=ใช่, 0=ไม่): ");
                    if (scanf("%d", &again) != 1) {
                        printf("อินพุตไม่ถูกต้อง\n");
                        return 1;
                    }
                    if (again != 1) break;
                }
            } while (paid != 1);

            if (paid == 1) {
                /* ปล่อยสินค้าและบันทึกยอดขาย */
                for (i = 0; i < 7; i++) {
                    if (cart[i] > 0) {
                        sale[i] += cart[i];
                        stock[i] -= cart[i];
                    }
                }
                printf("ชำระเงินสำเร็จ! รับสินค้าทั้งหมดเรียบร้อย\n");
            } else {
                printf("ยกเลิกรายการชำระเงิน\n");
            }

        } else if (method == 1) {
            /* เงินสด: รับจำนวนธนบัตร/เหรียญที่ลูกค้าใส่เข้ามา */
            int inBill[5] = {0, 0, 0, 0, 0};
            int inCoin[4] = {0, 0, 0, 0};
            int inserted = 0;

            printf("\nใส่จำนวนแบงก์ที่ชำระเข้ามา\n");
            for (i = 0; i < 5; i++) {
                printf("แบงก์ %d บาท : ", billDen[i]);
                if (scanf("%d", &inBill[i]) != 1) {
                    printf("อินพุตไม่ถูกต้อง\n");
                    return 1;
                }
                if (inBill[i] < 0) inBill[i] = 0;
                inserted += inBill[i] * billDen[i];
            }
            printf("ใส่จำนวนเหรียญที่ชำระเข้ามา\n");
            for (i = 0; i < 4; i++) {
                printf("เหรียญ %d บาท : ", coinDen[i]);
                if (scanf("%d", &inCoin[i]) != 1) {
                    printf("อินพุตไม่ถูกต้อง\n");
                    return 1;
                }
                if (inCoin[i] < 0) inCoin[i] = 0;
                inserted += inCoin[i] * coinDen[i];
            }

            if (inserted < total) {
                printf("ยอดเงินไม่พอ (ใส่ %d บาท ต้องการ %d บาท) ยกเลิกรายการและคืนเงิน\n", inserted, total);
            } else {
                int change = inserted - total;

                /* เติมเงินที่ลูกค้าใส่เข้ามาในคลังของตู้ (ชั่วคราว) */
                int tbillCnt[5];
                int tcoinCnt[4];
                for (i = 0; i < 5; i++) tbillCnt[i] = billCnt[i] + inBill[i];
                for (i = 0; i < 4; i++) tcoinCnt[i] = coinCnt[i] + inCoin[i];

                if (change == 0) {
                    /* ไม่ต้องทอน: commit เติมเงินเข้าตู้, ตัดสต็อก, บันทึกยอดขาย */
                    for (i = 0; i < 5; i++) billCnt[i] = tbillCnt[i];
                    for (i = 0; i < 4; i++) coinCnt[i] = tcoinCnt[i];
                    for (i = 0; i < 7; i++) {
                        if (cart[i] > 0) {
                            sale[i] += cart[i];
                            stock[i] -= cart[i];
                        }
                    }
                    printf("รับชำระเงินสดพอดี ไม่ต้องทอน\n");
                } else {
                    /* พยายามทอนแบบ greedy ด้วยคลังชั่วคราว tbill/tcoin */
                    int tmpChange = change;

                    /* ใช้แบงก์จากมากไปน้อย */
                    for (i = 0; i < 5 && tmpChange > 0; i++) {
                        while (tmpChange >= billDen[i] && tbillCnt[i] > 0) {
                            tmpChange -= billDen[i];
                            tbillCnt[i] -= 1;
                        }
                    }
                    /* ใช้เหรียญจากมากไปน้อย */
                    for (i = 0; i < 4 && tmpChange > 0; i++) {
                        while (tmpChange >= coinDen[i] && tcoinCnt[i] > 0) {
                            tmpChange -= coinDen[i];
                            tcoinCnt[i] -= 1;
                        }
                    }

                    if (tmpChange == 0) {
                        /* ทอนได้พอดี: commit คลังเงิน + ตัดสต็อก + บันทึกยอดขาย */
                        for (i = 0; i < 5; i++) billCnt[i] = tbillCnt[i];
                        for (i = 0; i < 4; i++) coinCnt[i] = tcoinCnt[i];
                        for (i = 0; i < 7; i++) {
                            if (cart[i] > 0) {
                                sale[i] += cart[i];
                                stock[i] -= cart[i];
                            }
                        }
                        printf("รับชำระเงินสด และทอนเงิน %d บาท เรียบร้อย\n", change);
                    } else {
                        /* ทอนไม่ได้: ยกเลิกรายการ และคืนเงิน */
                        printf("ขออภัย ตู้ไม่สามารถทอนเงินให้พอดี (ต้องทอน %d บาท)\n", change);
                        printf("กรุณาเลือกชำระแบบอื่น หรือยกเลิกรายการ\n");
                    }
                }
            }
        } else {
            printf("วิธีชำระไม่ถูกต้อง\n");
        }
    }

    /* ---------- สรุปผลท้ายโปรแกรม ---------- */
    printf("\n=== สรุปยอดขายสินค้า ===\n");
    for (i = 0; i < 7; i++) {
        printf("%-16s : ขายได้ %d ชิ้น | คงเหลือ %d | หมดอายุ(ครั้ง) %d\n",
               names[i], sale[i], stock[i], expired[i]);
    }

    /* สรุปยอดเงินคงเหลือในตู้ + แสดงจำนวนธนบัตร/เหรียญ */
    int machineTotal = 0;
    for (i = 0; i < 5; i++) machineTotal += billDen[i] * billCnt[i];
    for (i = 0; i < 4; i++) machineTotal += coinDen[i] * coinCnt[i];

    printf("\n=== เงินคงเหลือในตู้ (รวม %d บาท) ===\n", machineTotal);
    printf("ธนบัตร: ");
    for (i = 0; i < 5; i++) {
        if (billCnt[i] > 0) printf("%dบาท:%d  ", billDen[i], billCnt[i]);
        else printf("%dบาท:หมด  ", billDen[i]);
    }
    printf("\nเหรียญ:  ");
    for (i = 0; i < 4; i++) {
        if (coinCnt[i] > 0) printf("%dบาท:%d  ", coinDen[i], coinCnt[i]);
        else printf("%dบาท:หมด  ", coinDen[i]);
    }
    printf("\n");

    return 0;
}
