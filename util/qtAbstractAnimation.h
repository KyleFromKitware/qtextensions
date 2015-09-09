/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __qtAbstractAnimation_h
#define __qtAbstractAnimation_h

#include <QAbstractAnimation>

#include "../core/qtGlobal.h"

class qtAbstractAnimationPrivate;

class QTE_EXPORT qtAbstractAnimation : public QObject
{
  Q_OBJECT

  Q_PROPERTY(QAbstractAnimation::State state READ state NOTIFY stateChanged)
  Q_PROPERTY(int loopCount READ loopCount WRITE setLoopCount)
  Q_PROPERTY(double currentTime READ currentTime WRITE setCurrentTime)
  Q_PROPERTY(int currentLoop READ currentLoop NOTIFY currentLoopChanged)
  Q_PROPERTY(qreal rate READ rate WRITE setRate NOTIFY rateChanged)
  Q_PROPERTY(double duration READ duration)

public:
  qtAbstractAnimation(QObject* parent = 0);
  virtual ~qtAbstractAnimation();

  QAbstractAnimation::State state() const;
  qreal rate() const;

  double currentTime() const;
  double currentLoopTime() const;

  int loopCount() const;
  void setLoopCount(int loopCount);
  int currentLoop() const;

  virtual double duration() const = 0;
  double totalDuration() const;

signals:
  void finished();
  void stateChanged(QAbstractAnimation::State newState,
                    QAbstractAnimation::State oldState);
  void currentLoopChanged(int currentLoop);
  void rateChanged(qreal);

public slots:
  void start();
  void pause();
  void resume();
  void setPaused(bool);
  void stop();
  void setCurrentTime(double secs);
  void setRate(qreal rate);

protected:
  virtual void updateCurrentTime(double currentTime) = 0;
  virtual void updateState(QAbstractAnimation::State newState,
                           QAbstractAnimation::State oldState);
  virtual void updateRate(qreal rate);

protected:
  QTE_DECLARE_PRIVATE_PTR(qtAbstractAnimation)

private:
  QTE_DECLARE_PRIVATE(qtAbstractAnimation)
  Q_DISABLE_COPY(qtAbstractAnimation)
};

#endif
