rm(list=ls())
input <- read.csv("F:/Rajasree/R/2019_20SEMI/ML/Regression/DataSets/sample.csv")
attach(input)
names(input)
head(input,8)
plot(runs~at_bats,main="Runs Vs At_bats",xlim=c(1,6),ylim=c(1,6))
cor(runs,at_bats)
plotSS <- function(x, y, showSquares = FALSE, leastSquares = FALSE)
{
  plot(y~x, asp = 1, xlab=paste(substitute(x)), ylab=paste(substitute(y)))
  if(leastSquares)
  {
	m1 <- lm(y~x)
    y.hat <- m1$fit
  }
  else {
    cat("Click any two points to make a line.\n")
    pt1 <- locator(1)
    points(pt1$x, pt1$y, pch = 8, col = "red")
    pt2 <- locator(1)
    points(pt2$x, pt2$y, pch = 8, col = "red")
    pts <- data.frame("x" = c(pt1$x, pt2$x),"y" = c(pt1$y, pt2$y))
    m1 <- lm(y ~ x, data = pts)
    y.hat <- predict(m1, newdata = data.frame(x))
    # title(paste("b0 = ", pt1$y-(pt2$y-pt1$y)/(pt2$x-pt1$x)*pt1$x, ", b1 = ", (pt2$y-pt1$y)/(pt2$x-pt1$x)))
  }
  r <- y - y.hat
  abline(m1)
  oSide <- x - r
  LLim <- par()$usr[1]
  RLim <- par()$usr[2]
  oSide[oSide < LLim | oSide > RLim] <- c(x + r)[oSide < LLim | oSide > RLim]
  n <- length(y.hat)
  for(i in 1:n)
  {
    lines(rep(x[i], 2), c(y[i], y.hat[i]), lty = 2, col = "blue")
    if(showSquares)
    {
      lines(rep(oSide[i], 2), c(y[i], y.hat[i]), lty = 3, col = "orange")
      lines(c(oSide[i], x[i]), rep(y.hat[i],2), lty = 3, col = "orange")
      lines(c(oSide[i], x[i]), rep(y[i],2), lty = 3, col = "orange")
    }
  }
  SS <- round(sum(r^2), 3)
  cat("\r ")
  print(m1)
  cat("Sum of Squares: ", SS, "\n")
}
plotSS(x = at_bats, y = runs)
plotSS(x = at_bats, y = runs, showSquares = TRUE)
fit1 <- lm(runs ~ at_bats)
summary(fit1)
plotSS(x = at_bats, y = runs, leastSquares = TRUE)

