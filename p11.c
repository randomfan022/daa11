data()

mtcars

row <- nrow(mtcars)
col <- ncol(mtcars)

print(row)
print(col)

automatic <- 0
manual <- 0

for(i in 1:row)
  ifelse(mtcars[i,9] == 1, manual <- manual + 1, automatic <- automatic + 1)

ifelse(automatic > manual, "more automatic", "more manual")


x <- data.frame(mtcars)

hp <- x[,4]
weight <- x[,6]


scatter.smooth(hp, weight, span = 2/3, degree = 1, family=c("symmetric","gaussian"))

mpg <- x[,1]

hist(mpg, breaks = 12, col = "lightblue", border = "pink")

newmtcars = mtcars

newmtcars$am = as.integer(mtcars$am)
newmtcars$cyl = as.integer(mtcars$cyl)
newmtcars$vs = as.integer(mtcars$vs)

sapply(newmtcars,class)

mtcars[mtcars$cyl<5,]

