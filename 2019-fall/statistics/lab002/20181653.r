library(gdata)
data = read.xls("st_data.xls")
midterm = data$Midterm
breaks = seq(0, 100, by=10)
midterm.cut = cut(midterm, breaks, right=FALSE)
midterm.freq = table(midterm.cut)
print(cbind(midterm.freq))
readline()

hist(midterm, right=FALSE)
readline()

final = data$Final
plot(midterm, final, xlab="Midterm Exam", ylab="Final Exam")
readline()

print(mean(midterm))
print(var(midterm))
print(sd(midterm))
readline()