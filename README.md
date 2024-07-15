חוקי משחק:
אין סדר להטלת הקוביות בין השחקנים, כלומר אין תורות, השחקינים מחליטים ביניהם מתי כל אחד מטיל את הקובייה. 
כל שחקן מתחיל את המשחק עם 2 יישובים ו-2 קטעי דרך המעניקים לו 2 נקודות ניצחון.
כאשר שחקן מגיע ל-10 נקודות המשחק התכנית לא נסגרת (כי כל הפקודות של התורות נרשמות בmain אז אין דרך לדעת מתי מישהו ניצח), לכן כאשר מישהו מגיע ל-10 נקודות השחקנים בעצמם מחליטים על הניצחון.
האיזורים בלוח בנויים בדיוק כמו בציור שבקישור של המטלה.
יש חבילת קלפים המכילה קלפי פיתוח (אין חבילה כזו למשאבים, כלומר יש אפשרות להשיג אינסוף מכל משאב), כאשר בחבילה ישנם: 14 כלפי אביר, 2 מונופול, 2 בניית דרכים, ו-5 שנת שפע.
כאשר שחקן משיג 3 כלפי אביר הוא מקבל 2 נקודות ניצחון עד שיהיה לו פחות מ3 קלפי אביר.
העלויות של קלפי פיתוח, קטעי דרך, ישובים וערים הם כמו העלויות במשחק.
ניתן לבנות עיר רק על מקום שלאותו השקן יש ישוב.


הסבר על המחלקות\היררכיה:
מחלקת catan מחזיקה את כל השחקנים, את לוח המשחק, ואת חפיסת קלפי הפיתוח.

מחלקת player מחזיקה את כמות המשאבים, את כלפי הפיתוח ומספר נקודות ניצחון שהשחקן צבר, ובנוסף את המטודות של הטלת קובייה, בניית ערים\יישובים\קטעי דרך וכו..

הקובץ places.hpp מכיל מחלקות עבור כל איזור (הרים, שדות וכו..), כאשר כל מחלקה כזו יורשת ממחלקת place שהיא מחקלה שמוגדרות בה הפונקציות והאמצעים המזהים (כמו מספר האיזור, שם האיזור וכו..) של כל איזור,
ובנוסף מוגדר בה ווקטור של מצביעים לקטעי דרך סביב אותו איזור (מצביע למחלקה מסוג Buildble), ווקטור של מצביעים למקומות שניתן לבנות בהם יישוב סביב אותו איזור (גם מסוג Buildable).

מחלקת board מחזיקה את כל האיזורים של המפה בתוך ווקטור של ווקטורים (מסוג place), ובנוסף מטריצה של כל המקומות במפה שניתן לבנות בהם קטע דרך (מסוג Buldable) ומטריצה של כל המקומות שניתן לבנות בהם יישוב (גם מסוג Buildable).
כאשר יוצרים אובייקט של Board אז בבנאי מתממשת פונקציית InitBoard שעוברת על כל האיזורים של המפה ושמה בכל ווקטור של מצביעים לBuildable של אותו איזור את הAdress של האינדקס של המטריצה המתאימה (מטריצת היישובים או מטריצת קטעי דרך).
כלומר עבור שתי איזורים סמוכים במפה x ו-y, אם שחקן בנה קטע דרך מימין ל-y, אז הוא בעצם בנה גם קטע דרך משמאל ל-x כי במפת המצביעים לקטעי הדרך של שני האיזורים, הם שניהם מצביעים לאותו מקום במטריצת קטעי הדרך במחלקת Board.

הקובץ buildable.hpp מכיל את מחקלת Buildable, ועוד שלוש מחלקות- Road, Settlment, City, כאשר שלושתם יורשים ממחלקת Buildable, שמחזיקה את השחקן שהוא הבעלים של אותו Buildable, ואת השם של הBuildable (קטע דרך, עיר או יישוב).

מחלקת Deck מחזיקה ווקטור של קלפי פיתוח שכל אחד מהם הוא מסוג Card.

מחלקת Card את השם של קלף הפיתוח ואת הכמות שיש מאותו הקלף (השקן מתחיל כאשר ישלו כמות 0 מכל קלף, אבל בdeck אני מאתחל את הכמות של כל קלף).


